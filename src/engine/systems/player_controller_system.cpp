//
// Created by simone on 03/03/26.
//

#include "player_controller_system.hpp"

#include "../components/input_state_component.hpp"
#include "../components/velocity_component.hpp"
#include "../components/state_component.hpp"
#include "../components/tags/player_tag.hpp"

PlayerControllerSystem::PlayerControllerSystem(entt::registry* registry) : System(registry) {
}

void PlayerControllerSystem::update(int elapsed) {
    auto player = registry_->view<PlayerTag>().front();
    handle_input(player);
}

void PlayerControllerSystem::handle_input(const entt::entity player) const {
    auto input = registry_->ctx().get<InputStateComponent>();
    auto &vel = registry_->get_or_emplace<VelocityComponent>(player);
    vel.acceleration = input.request_player_movement * vel.acceleration_strength;
    if (vel.acceleration.x != 0.f || vel.acceleration.y != 0.f) {
        vel.active = true;
        registry_->get<StateComponent>(player).is_moving = true;
    }
}
