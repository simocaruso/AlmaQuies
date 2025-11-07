//
// Created by simone on 07/11/25.
//

#include "movement_system.hpp"
#include "events/move_command_event.hpp"
#include "../components/velocity_component.hpp"
#include "../components/transform_component.hpp"

MovementSystem::MovementSystem(entt::registry *registry, entt::dispatcher &dispatcher) : System(registry) {
    dispatcher.sink<MoveCommandEvent>().connect<&MovementSystem::on_move_command>(this);
}

void MovementSystem::on_move_command(const MoveCommandEvent &event) {
    auto &vel = registry_->get_or_emplace<VelocityComponent>(event.entity);
    vel.acceleration = event.direction * vel.acceleration_strength;
    vel.active = true;
}

void MovementSystem::update(int elapsed) {
    auto view = registry_->view<TransformComponent, VelocityComponent>();

    for (auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &vel = view.get<VelocityComponent>(entity);

        if (vel.active)
            vel.speed += vel.acceleration * elapsed / 1000;

        if (!vel.active) {
            float deceleration_amount = vel.deceleration_strength * elapsed / 1000;
            vel.speed = vel.speed.normalized() * std::max(0.0f, vel.speed.length() - deceleration_amount);
        }

        if (vel.speed.length() > vel.max_speed)
            vel.speed = vel.speed.normalized() * vel.max_speed;

        transform.position += vel.speed * elapsed / 1000;
        vel.active = false;
    }
}
