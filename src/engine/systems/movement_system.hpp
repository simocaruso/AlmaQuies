//
// Created by simone on 07/11/25.
//

#ifndef FARMANDCONQUER_MOVEMENT_SYSTEM_HPP
#define FARMANDCONQUER_MOVEMENT_SYSTEM_HPP


#include "system.hpp"
#include "events/move_command_event.hpp"

class MovementSystem : public System {
public:
    MovementSystem(entt::registry *registry, entt::dispatcher &dispatcher);

    void update(int elapsed) override;

    void on_move_command(const MoveCommandEvent &event);
};


#endif //FARMANDCONQUER_MOVEMENT_SYSTEM_HPP
