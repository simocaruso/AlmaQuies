//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_CREATED_COLLIDABLE_EVENT_HPP
#define FARMANDCONQUER_CREATED_COLLIDABLE_EVENT_HPP

#include "entt/entt.hpp"

struct CreatedCollidableEvent {
    entt::entity entity;
    Vec2 position;
};

#endif //FARMANDCONQUER_CREATED_COLLIDABLE_EVENT_HPP
