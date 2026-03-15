//
// Created by simone on 14/03/26.
//

#include "ai_controller_system.hpp"
#include "../components/tags/ai_controlled_tag.hpp"
#include "../components/tags/selected_tag.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"
#include "../components/state_component.hpp"
#include "../../util/movement_util.hpp"

static constexpr float ARRIVAL_DISTANCE = 20.0f;

AIControllerSystem::AIControllerSystem(entt::registry* registry) : System(registry) {}

void AIControllerSystem::update(int elapsed) {
    auto selected_view = registry_->view<SelectedTag>();
    if (selected_view.empty()) return;

    const auto selected = selected_view.front();
    const auto target = registry_->get<TransformComponent>(selected).position;

    auto view = registry_->view<AIControlledTag, TransformComponent, VelocityComponent>();
    for (const auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &vel       = view.get<VelocityComponent>(entity);

        const auto delta = target - transform.position;
        if (delta.length() <= ARRIVAL_DISTANCE) {
            registry_->remove<SelectedTag>(selected);
            registry_->remove<AIControlledTag>(entity);
            return;
        }

        const Vec2 direction = MovementUtil::get_direction(transform.position, target);
        vel.acceleration = direction * vel.acceleration_strength;
        vel.active = true;
        registry_->get<StateComponent>(entity).is_moving = true;
    }
}
