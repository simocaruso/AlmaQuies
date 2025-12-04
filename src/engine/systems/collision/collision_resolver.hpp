//
// Created by simone on 14/11/25.
//

#ifndef FARMANDCONQUER_COLLISION_RESOLVER_HPP
#define FARMANDCONQUER_COLLISION_RESOLVER_HPP

#include "entt/entt.hpp"

class CollisionResolver {
public:
    static void resolve_collision(entt::registry* registry, entt::entity entity1, entt::entity entity2);

private:
    static void get_data(entt::registry* registry, entt::entity entity);
};


#endif //FARMANDCONQUER_COLLISION_RESOLVER_HPP
