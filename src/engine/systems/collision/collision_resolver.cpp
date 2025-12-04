//
// Created by simone on 14/11/25.
//

#include "collision_resolver.hpp"
#include "entt/entt.hpp"
#include "../../components/velocity_component.hpp"
#include "../../components/transform_component.hpp"

void CollisionResolver::resolve_collision(entt::registry* registry, entt::entity entity1, entt::entity entity2) {
    get_data(registry, entity1);
    get_data(registry, entity2);
}

void CollisionResolver::get_data(entt::registry* registry, entt::entity entity) {
    if (registry->try_get<VelocityComponent>(entity))
        registry->get<VelocityComponent>(entity).speed = {0, 0};
    auto &transform = registry->get<TransformComponent>(entity);
    transform.position = transform.prev_position;
}
