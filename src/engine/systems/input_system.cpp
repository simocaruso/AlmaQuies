//
// Created by simone on 07/11/25.
//

#include "input_system.hpp"

#include "../components/camera_component.hpp"
#include "../components/input_state_component.hpp"
#include "../components/tags/player_tag.hpp"
#include "events/move_command_event.hpp"
#include "events/zoom_command_event.hpp"

InputSystem::InputSystem(entt::registry* registry, InputManager* input_manager,
                         entt::dispatcher* dispatcher) : System(registry), input_manager_(input_manager),
                                                         dispatcher_(dispatcher) {
    registry_->ctx().emplace<InputStateComponent>();
}

void InputSystem::update(int elapsed) {
    input_manager_->update();
    update_mouse_state();
    process_movement();
    process_camera();
}

void InputSystem::update_mouse_state() const {
    auto &input = registry_->ctx().get<InputStateComponent>();
    input.mouse_x = input_manager_->mouse_position().x;
    input.mouse_y = input_manager_->mouse_position().y;
    input.left_click = input_manager_->mouse_button_down(ALLEGRO_MOUSE_BUTTON_LEFT);

    auto camera = registry_->view<CameraComponent>().front();
    auto camera_transform = registry_->get<CameraComponent>(camera).transform;
    al_invert_transform(&camera_transform);
    al_transform_coordinates(&camera_transform, &input.mouse_x, &input.mouse_y);
}

void InputSystem::process_movement() const {
    Vec2 dir = {0, 0};
    if (input_manager_->key_down(ALLEGRO_KEY_W)) dir.y -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_S)) dir.y += 1;
    if (input_manager_->key_down(ALLEGRO_KEY_A)) dir.x -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_D)) dir.x += 1;

    if (dir.x != 0 || dir.y != 0) {
        auto view = registry_->view<PlayerTag>();
        for (auto e: view) {
            dispatcher_->enqueue(MoveCommandEvent{e, dir});
        }
    }
}

void InputSystem::process_camera() const {
    Vec2 dir = {0, 0};
    if (input_manager_->key_down(ALLEGRO_KEY_UP)) dir.y -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_DOWN)) dir.y += 1;
    if (input_manager_->key_down(ALLEGRO_KEY_LEFT)) dir.x -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_RIGHT)) dir.x += 1;

    if (dir.x != 0 || dir.y != 0) {
        auto view = registry_->view<CameraComponent>();
        for (auto e: view) {
            dispatcher_->enqueue(MoveCommandEvent{e, dir});
        }
    }

    int zoom_factor = input_manager_->mouse_wheel_delta();
    if (zoom_factor != 0) {
        auto view = registry_->view<CameraComponent>();
        for (auto e: view) {
            dispatcher_->enqueue(ZoomCommandEvent{e, zoom_factor});
        }
    }
}
