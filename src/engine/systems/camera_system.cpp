//
// Created by simone on 14/11/25.
//

#include "camera_system.hpp"

#include "../components/camera_component.hpp"
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
}
