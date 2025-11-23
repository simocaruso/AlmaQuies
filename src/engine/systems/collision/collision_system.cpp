//
// Created by simone on 13/11/25.
//

#include "collision_system.hpp"

#include "collision_checker.hpp"
#include "collision_resolver.hpp"
#include "../../../util/constants.hpp"
#include "../../components/collider_component.hpp"
#include "../../components/transform_component.hpp"
#include "../../components/velocity_component.hpp"


CollisionSystem::CollisionSystem(SpatialGrid *grid, entt::registry *registry, entt::dispatcher &dispatcher)
    : System(registry), grid_(grid) {
}

void CollisionSystem::update(int elapsed) {
    check_collisions();
}

void CollisionSystem::check_collisions() const {
    auto view = registry_->view<TransformComponent, ColliderComponent>();
    for (const auto e1: view) {
        auto &t1 = view.get<TransformComponent>(e1);
        auto &c1 = view.get<ColliderComponent>(e1);
        auto nearby = grid_->query_nearby(t1.position, compute_radius(c1));
        for (const auto e2: nearby) {
            if (e1 == e2) continue;
            if (!view.contains(e2)) continue;
            auto &t2 = view.get<TransformComponent>(e2);
            auto &c2 = view.get<ColliderComponent>(e2);
            if (CollisionChecker::collide(t1, c1, t2, c2)) {
                CollisionResolver::resolve_collision(t1, t2);
            }
        }
    }
}

float CollisionSystem::compute_radius(const ColliderComponent &collider) const {
    return std::visit([]<typename T>(T &&shape) -> float {
        if constexpr (std::is_same_v<T, CircleCollider>) {
            return shape.radius;
        } else if constexpr (std::is_same_v<T, RectCollider>) {
            // radius = half diagonal of rectangle
            return std::sqrt((shape.width * shape.width + shape.height * shape.height) / 4.0f);
        }
        return 0;
    }, collider.data);
}
