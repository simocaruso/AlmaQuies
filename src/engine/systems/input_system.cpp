//
// Created by simone on 07/11/25.
//

#include "input_system.hpp"
#include "../components/player_tag.hpp"
#include "events/move_command_event.hpp"

InputSystem::InputSystem(entt::registry *registry, InputManager *input_manager, entt::dispatcher *dispatcher) :
        System(registry), input_manager_(input_manager), dispatcher_(dispatcher) {
}

void InputSystem::update(int elapsed) {
    input_manager_->update();
    process_movement();
}

void InputSystem::process_movement() {
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