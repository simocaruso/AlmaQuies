//
// Created by simone on 14/11/25.
//

#ifndef ALMAQUIES_COLLISION_RESOLVER_HPP
#define ALMAQUIES_COLLISION_RESOLVER_HPP

#include "entt/entt.hpp"

class CollisionResolver {
public:
    static void resolve_collision(entt::registry* registry, entt::entity entity1, entt::entity entity2);

private:
    static void get_data(entt::registry* registry, entt::entity entity);
};


#endif //ALMAQUIES_COLLISION_RESOLVER_HPP
