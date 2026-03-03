//
// Created by simone on 07/11/25.
//

#include "input_system.hpp"

#include "../components/camera_component.hpp"
#include "../components/input_state_component.hpp"

InputSystem::InputSystem(entt::registry* registry, InputManager* input_manager)
    : System(registry), input_manager_(input_manager) {
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
    auto &input = registry_->ctx().get<InputStateComponent>();
    input.request_player_movement = {0, 0};
    if (input_manager_->key_down(ALLEGRO_KEY_W)) input.request_player_movement.y -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_S)) input.request_player_movement.y += 1;
    if (input_manager_->key_down(ALLEGRO_KEY_A)) input.request_player_movement.x -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_D)) input.request_player_movement.x += 1;
}

void InputSystem::process_camera() const {
    auto &input = registry_->ctx().get<InputStateComponent>();
    input.request_camera_movement = {0, 0};
    if (input_manager_->key_down(ALLEGRO_KEY_UP)) input.request_camera_movement.y -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_DOWN)) input.request_camera_movement.y += 1;
    if (input_manager_->key_down(ALLEGRO_KEY_LEFT)) input.request_camera_movement.x -= 1;
    if (input_manager_->key_down(ALLEGRO_KEY_RIGHT)) input.request_camera_movement.x += 1;

    const int zoom_factor = input_manager_->mouse_wheel_delta();
    if (zoom_factor != 0) {
        input.request_camera_zoom = zoom_factor;
    }
}
