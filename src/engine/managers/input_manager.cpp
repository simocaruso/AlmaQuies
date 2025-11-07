//
// Created by simone on 07/11/25.
//

#include <cstring>
#include "input_manager.hpp"

InputManager::InputManager() {
    al_install_mouse();
    al_install_keyboard();

    queue_ = al_create_event_queue();
    al_register_event_source(queue_, al_get_keyboard_event_source());
    al_register_event_source(queue_, al_get_mouse_event_source());
}

InputManager::~InputManager() {
    if (queue_)
        al_destroy_event_queue(queue_);
}

void InputManager::update() {
    std::memcpy(prev_keys_, keys_, sizeof(keys_));
    std::memcpy(prev_mouse_buttons_, mouse_buttons_, sizeof(mouse_buttons_));

    ALLEGRO_EVENT ev;
    while (al_get_next_event(queue_, &ev)) {
        handle_event(ev);
    }
}

bool InputManager::key_down(int keycode) const {
    return keys_[keycode];
}

bool InputManager::key_pressed(int keycode) const {
    return keys_[keycode] && !prev_keys_[keycode];
}

bool InputManager::key_released(int keycode) const {
    return !keys_[keycode] && prev_keys_[keycode];
}

bool InputManager::mouse_button_down(int button) const {
    return mouse_buttons_[button];
}

bool InputManager::mouse_button_pressed(int button) const {
    return mouse_buttons_[button] && !prev_mouse_buttons_[button];
}

bool InputManager::mouse_button_released(int button) const {
    return !mouse_buttons_[button] && prev_mouse_buttons_[button];
}

void InputManager::handle_event(const ALLEGRO_EVENT &event) {
    switch (event.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            keys_[event.keyboard.keycode] = true;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            keys_[event.keyboard.keycode] = false;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            mouse_buttons_[event.mouse.button] = true;
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            mouse_buttons_[event.mouse.button] = false;
            break;
        case ALLEGRO_EVENT_MOUSE_AXES:
            mouse_position_.x = event.mouse.x;
            mouse_position_.y = event.mouse.y;
            break;
    }
}

