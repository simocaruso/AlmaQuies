//
// Created by simone on 07/11/25.
//

#include "movement_system.hpp"

#include "../components/state_component.hpp"
#include "../components/velocity_component.hpp"
#include "../components/transform_component.hpp"

MovementSystem::MovementSystem(entt::registry* registry, entt::dispatcher &dispatcher) : System(registry) {
}


void MovementSystem::update(int elapsed) {
    auto view = registry_->view<TransformComponent, VelocityComponent>();

    for (auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &vel = view.get<VelocityComponent>(entity);

        if (vel.active)
            vel.speed += vel.acceleration * elapsed / 1000;

        if (!vel.active) {
            float deceleration_amount = 2 * vel.deceleration_strength * elapsed / 1000;
            vel.speed = vel.speed.normalized() * std::max(0.0f, vel.speed.length() - deceleration_amount);
        } else {
            if (std::abs(vel.acceleration.x) < 0.0001f) {
                apply_deceleration_axis(vel.speed.x, vel.deceleration_strength, elapsed);
            }

            if (std::abs(vel.acceleration.y) < 0.001f) {
                apply_deceleration_axis(vel.speed.y, vel.deceleration_strength, elapsed);
            }
        }
        if (vel.speed.length() > vel.max_speed)
            vel.speed = vel.speed.normalized() * vel.max_speed;

        transform.prev_position = transform.position;
        transform.position += vel.speed * elapsed / 1000;
        vel.active = false;
        if (vel.speed.length() < 0.001f && registry_->all_of<StateComponent>(entity))
            registry_->get<StateComponent>(entity).is_moving = false;
    }
}

void MovementSystem::apply_deceleration_axis(float &v, const float deceleration_strength, const int elapsed) {
    if (v > 0) {
        v = std::max(0.0f, v - deceleration_strength * elapsed / 1000);
    } else if (v < 0) {
        v = std::min(0.0f, v + deceleration_strength * elapsed / 1000);
    }
}
