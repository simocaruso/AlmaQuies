//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_COLLISION_SYSTEM_HPP
#define FARMANDCONQUER_COLLISION_SYSTEM_HPP

#include "../../../../engine/spatial_grid.hpp"
#include "../system.hpp"

class CollisionSystem : public System {
public:
    CollisionSystem(SpatialGrid *grid, entt::registry *registry);

    void update(int elapsed) override;

private:
    SpatialGrid *grid_;

    void check_collisions() const;
};


#endif //FARMANDCONQUER_COLLISION_SYSTEM_HPP
