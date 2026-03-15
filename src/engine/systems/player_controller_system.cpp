//
// Created by simone on 03/03/26.
//

#include "player_controller_system.hpp"
#include "../components/input_state_component.hpp"
#include "../components/tags/selected_tag.hpp"
#include "../components/tags/ai_controlled_tag.hpp"
#include "../components/velocity_component.hpp"
#include "../components/state_component.hpp"
#include "../components/tags/player_tag.hpp"

PlayerControllerSystem::PlayerControllerSystem(entt::registry* registry) : System(registry) {}

void PlayerControllerSystem::update(int elapsed) {
    const auto player = registry_->view<PlayerTag>().front();
    update_ai_tag(player);
    if (!registry_->all_of<AIControlledTag>(player))
        move_to(player, registry_->ctx().get<InputStateComponent>().request_player_movement);
}

void PlayerControllerSystem::update_ai_tag(const entt::entity player) const {
    if (registry_->view<SelectedTag>().empty()) {
        registry_->remove<AIControlledTag>(player);
    } else {
        if (!registry_->all_of<AIControlledTag>(player))
            registry_->emplace<AIControlledTag>(player);
    }
}

void PlayerControllerSystem::move_to(const entt::entity player, const Vec2 direction) const {
    auto &vel = registry_->get_or_emplace<VelocityComponent>(player);
    vel.acceleration = direction * vel.acceleration_strength;
    if (vel.acceleration.x != 0.f || vel.acceleration.y != 0.f) {
        vel.active = true;
        registry_->get<StateComponent>(player).is_moving = true;
    }
}
