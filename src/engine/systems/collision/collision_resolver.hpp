//
// Created by simone on 14/11/25.
//

#ifndef FARMANDCONQUER_COLLISION_RESOLVER_HPP
#define FARMANDCONQUER_COLLISION_RESOLVER_HPP

#include "../../components/transform_component.hpp"

class CollisionResolver {
public:
    static void resolve_collision(TransformComponent &t1, TransformComponent &t2);
};


#endif //FARMANDCONQUER_COLLISION_RESOLVER_HPP
