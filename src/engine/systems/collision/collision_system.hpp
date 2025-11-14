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
    CollisionSystem(entt::registry* registry, entt::dispatcher &dispatcher);

    void update(int elapsed) override;

private:
    SpatialGrid grid_;

    void clear_moving_entities();

    void register_moving_entities();

    void check_collisions() const;

    void on_created_collidable(const CreatedCollidableEvent &event);

    float compute_radius(const ColliderComponent &collider) const;
};


#endif //FARMANDCONQUER_COLLISION_SYSTEM_HPP
