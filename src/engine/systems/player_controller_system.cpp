//
// Created by simone on 03/03/26.
//

#include "player_controller_system.hpp"

#include "../../util/movement_util.hpp"
#include "../components/input_state_component.hpp"
#include "../components/selected_tag.hpp"
#include "../components/velocity_component.hpp"
#include "../components/state_component.hpp"
#include "../components/transform_component.hpp"
#include "../components/tags/player_tag.hpp"

PlayerControllerSystem::PlayerControllerSystem(entt::registry* registry) : System(registry) {
}

void PlayerControllerSystem::update(int elapsed) {
    auto player = registry_->view<PlayerTag>().front();
    update_movement(player);
}

void PlayerControllerSystem::update_movement(const entt::entity player) const {
    Vec2 direction;
    if (!registry_->view<SelectedTag>().empty()) {
        const auto pos = registry_->get<TransformComponent>(player).position;
        const auto target = registry_->get<TransformComponent>(registry_->view<SelectedTag>().front()).position;
        direction = MovementUtil::get_direction(pos, target);
    } else {
        direction = registry_->ctx().get<InputStateComponent>().request_player_movement;
    }
    move_to(player, direction);
}

void PlayerControllerSystem::move_to(const entt::entity player, const Vec2 direction) const {
    auto &vel = registry_->get_or_emplace<VelocityComponent>(player);
    vel.acceleration = direction * vel.acceleration_strength;
    if (vel.acceleration.x != 0.f || vel.acceleration.y != 0.f) {
        vel.active = true;
        registry_->get<StateComponent>(player).is_moving = true;
    }
}
