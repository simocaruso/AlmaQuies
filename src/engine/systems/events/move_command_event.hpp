//
// Created by simone on 07/11/25.
//

#ifndef FARMANDCONQUER_MOVE_COMMAND_EVENT_HPP
#define FARMANDCONQUER_MOVE_COMMAND_EVENT_HPP

#include "entt/entt.hpp"
#include "../../../util/vec_2.hpp"

struct MoveCommandEvent {
    entt::entity entity;
    Vec2 direction;
};

#endif //FARMANDCONQUER_MOVE_COMMAND_EVENT_HPP
