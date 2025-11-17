//
// Created by simone on 07/11/25.
//

#ifndef FARMANDCONQUER_INPUT_MANAGER_HPP
#define FARMANDCONQUER_INPUT_MANAGER_HPP

#include <allegro5/allegro.h>
#include "../display.hpp"
#include "../../util/vec_2.hpp"


class InputManager {
public:
    InputManager();

    ~InputManager();

    void update();

    bool key_down(int keycode) const;

    bool key_pressed(int keycode) const;

    bool key_released(int keycode) const;

    bool mouse_button_down(int button) const;

    bool mouse_button_pressed(int button) const;

    bool mouse_button_released(int button) const;

    int mouse_wheel_delta();

    Vec2 mouse_position() const;

private:
    ALLEGRO_EVENT_QUEUE* queue_ = nullptr;
    bool keys_[ALLEGRO_KEY_MAX] = {false};
    bool prev_keys_[ALLEGRO_KEY_MAX] = {false};
    bool mouse_buttons_[8] = {false};
    bool prev_mouse_buttons_[8] = {false};
    int mouse_wheel_delta_{0};
    Vec2 mouse_position_;

    void handle_event(const ALLEGRO_EVENT &event);
};


#endif //FARMANDCONQUER_INPUT_MANAGER_HPP
