//
// Created by simone on 07/11/25.
//

#ifndef ALMAQUIES_INPUT_SYSTEM_HPP
#define ALMAQUIES_INPUT_SYSTEM_HPP


#include "../managers/input_manager.hpp"
#include "entt/entt.hpp"
#include "system.hpp"

class InputSystem : public System {
public:
    InputSystem(entt::registry* registry, InputManager* input_manager);

    void update(int elapsed) override;

private:
    InputManager* input_manager_;

    void update_mouse_state() const;

    void process_movement() const;

    void process_camera() const;
};


#endif //ALMAQUIES_INPUT_SYSTEM_HPP
