//
// Created by simone on 14/11/25.
//

#include "camera_system.hpp"

#include "../components/camera_component.hpp"
#include "../components/tags/player_tag.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"
#include "events/zoom_command_event.hpp"

CameraSystem::CameraSystem(entt::registry* registry, entt::dispatcher &dispatcher) : System(registry) {
    dispatcher.sink<ZoomCommandEvent>().connect<&CameraSystem::on_zoom>(this);
}

void CameraSystem::on_zoom(ZoomCommandEvent zoom_event) {
    auto &camera = registry_->get<CameraComponent>(zoom_event.camera);
    camera.zoom *= 1.0f - zoom_event.zoom_factor * camera.scroll_direction * camera.zoom_sensitivity;
    if (camera.zoom > camera.camera_max_zoom) {
        camera.zoom = camera.camera_max_zoom;
    }
    if (camera.zoom < camera.camera_min_zoom) {
        camera.zoom = camera.camera_min_zoom;
    }
}

void CameraSystem::update(int elapsed) {
    auto camera = registry_->view<CameraComponent>().front();
    const auto velocity = registry_->get<VelocityComponent>(camera);
    if (!velocity.active) {
        const auto player = registry_->view<PlayerTag>().front();
        auto &camera_pos = registry_->get<TransformComponent>(camera).position;
        const auto player_pos = registry_->get<TransformComponent>(player).position;
        camera_pos = player_pos - Vec2{BUFF_W / 2.0f, BUFF_H / 2.0f};
    }
}
