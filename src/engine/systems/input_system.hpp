//
// Created by simone on 07/11/25.
//

#ifndef FARMANDCONQUER_INPUT_SYSTEM_HPP
#define FARMANDCONQUER_INPUT_SYSTEM_HPP


#include "../managers/input_manager.hpp"
#include "entt/entt.hpp"
#include "system.hpp"

class InputSystem : public System {
public:
    InputSystem(entt::registry* registry, InputManager* input_manager, entt::dispatcher* dispatcher);

    void update(int elapsed) override;

private:
    InputManager* input_manager_;
    entt::dispatcher* dispatcher_;

    void update_mouse_state() const;

    void process_movement() const;

    void process_camera() const;
};


#endif //FARMANDCONQUER_INPUT_SYSTEM_HPP
