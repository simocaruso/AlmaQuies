//
// Created by simone on 13/11/25.
//

#include "collision_system.hpp"

#include "collision_checker.hpp"
#include "collision_resolver.hpp"
#include "../../components/collider_component.hpp"
#include "../../components/transform_component.hpp"
#include "../../../util/util.hpp"
#include "../../components/velocity_component.hpp"

CollisionSystem::CollisionSystem(SpatialGrid* grid, entt::registry* registry)
    : System(registry), grid_(grid) {
}

void CollisionSystem::update(int elapsed) {
    check_collisions();
}

void CollisionSystem::check_collisions() const {
    auto view = registry_->view<TransformComponent, VelocityComponent, ColliderComponent>();
    for (const auto e1: view) {
        auto &t1 = view.get<TransformComponent>(e1);
        auto &c1 = view.get<ColliderComponent>(e1);
        auto nearby = grid_->query_nearby(t1.position, compute_radius(c1));
        for (const auto e2: nearby) {
            if (e1 == e2) continue;
            auto &t2 = view.get<TransformComponent>(e2);
            auto &c2 = view.get<ColliderComponent>(e2);
            if (CollisionChecker::collide(t1.position, c1, t2.position, c2)) {
                CollisionResolver::resolve_collision(t1, t2);
            }
        }
    }
}

