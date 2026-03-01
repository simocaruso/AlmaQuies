//
// Created by simone on 13/11/25.
//

#ifndef ALMAQUIES_CREATED_COLLIDABLE_EVENT_HPP
#define ALMAQUIES_CREATED_COLLIDABLE_EVENT_HPP

#include "entt/entt.hpp"

struct CreatedCollidableEvent {
    entt::entity entity;
    Vec2 position;
    ColliderComponent collider;
};

#endif //ALMAQUIES_CREATED_COLLIDABLE_EVENT_HPP
