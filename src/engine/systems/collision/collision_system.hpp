//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_COLLISION_SYSTEM_HPP
#define FARMANDCONQUER_COLLISION_SYSTEM_HPP

#include "spatial_grid.hpp"
#include "../system.hpp"
#include "../events/created_collidable_event.hpp"
#include "../../components/collider_component.hpp"

class CollisionSystem : public System {
public:
    CollisionSystem(SpatialGrid *grid, entt::registry *registry, entt::dispatcher &dispatcher);

    void update(int elapsed) override;

private:
    SpatialGrid *grid_;

    void check_collisions() const;

    float compute_radius(const ColliderComponent &collider) const;
};


#endif //FARMANDCONQUER_COLLISION_SYSTEM_HPP
