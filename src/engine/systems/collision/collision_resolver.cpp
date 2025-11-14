//
// Created by simone on 14/11/25.
//

#include "collision_resolver.hpp"

void CollisionResolver::resolve_collision(TransformComponent &t1, TransformComponent &t2) {
    t1.position = t1.prev_position;
    t2.position = t2.prev_position;
}
