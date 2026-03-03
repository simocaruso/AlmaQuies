//
// Created by simone on 14/11/25.
//

#include "camera_system.hpp"

#include "../components/camera_component.hpp"
#include "../components/tags/player_tag.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"
#include "../components/input_state_component.hpp"

CameraSystem::CameraSystem(entt::registry* registry) : System(registry) {
}

void CameraSystem::update(int elapsed) {
    auto camera = registry_->view<CameraComponent>().front();
    handle_input(camera);

    const auto velocity = registry_->get<VelocityComponent>(camera);
    if (!velocity.active) {
        const auto player = registry_->view<PlayerTag>().front();
        auto &camera_pos = registry_->get<TransformComponent>(camera).position;
        const auto player_pos = registry_->get<TransformComponent>(player).position;
        camera_pos = player_pos - Vec2{BUFF_W / 2.0f, BUFF_H / 2.0f};
    }
}

void CameraSystem::handle_input(const entt::entity camera) const {
    handle_movement(camera);
    handle_zoom(camera);
}

void CameraSystem::handle_movement(const entt::entity camera) const {
    auto input = registry_->ctx().get<InputStateComponent>();
    auto &vel = registry_->get_or_emplace<VelocityComponent>(camera);
    vel.acceleration = input.request_camera_movement * vel.acceleration_strength;
    if (vel.acceleration.x != 0.f || vel.acceleration.y != 0.f) {
        vel.active = true;
    }
}

void CameraSystem::handle_zoom(const entt::entity camera) const {
    const auto input = registry_->ctx().get<InputStateComponent>();
    auto &camera_component = registry_->get<CameraComponent>(camera);
    camera_component.zoom *= 1.0f - input.request_camera_zoom *
            camera_component.scroll_direction * camera_component.zoom_sensitivity;
    if (camera_component.zoom > camera_component.camera_max_zoom) {
        camera_component.zoom = camera_component.camera_max_zoom;
    }
    if (camera_component.zoom < camera_component.camera_min_zoom) {
        camera_component.zoom = camera_component.camera_min_zoom;
    }
}
