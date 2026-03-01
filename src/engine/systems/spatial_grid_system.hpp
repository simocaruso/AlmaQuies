//
// Created by simone on 23/11/25.
//

#ifndef ALMAQUIES_SPATIAL_GRID_SYSTEM_HPP
#define ALMAQUIES_SPATIAL_GRID_SYSTEM_HPP
#include "system.hpp"
#include "../../../engine/spatial_grid.hpp"
#include "events/created_collidable_event.hpp"
#include "events/created_renderable_event.hpp"


class SpatialGridSystem : public System {
public:
    SpatialGridSystem(SpatialGrid* rendering_grid, SpatialGrid* physic_grid, entt::registry* registry);

    void update(int elapsed) override;

    void on_created_collidable(entt::registry &registry, entt::entity entity);

    void on_created_renderable(entt::registry &registry, entt::entity entity);

private:
    SpatialGrid* rendering_grid_;
    SpatialGrid* physic_grid_;

    void clear_moving_entities() const;

    void register_moving_entities() const;
};


#endif //ALMAQUIES_SPATIAL_GRID_SYSTEM_HPP
