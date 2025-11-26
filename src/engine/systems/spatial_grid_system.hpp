//
// Created by simone on 23/11/25.
//

#ifndef FARMANDCONQUER_SPATIAL_GRID_SYSTEM_HPP
#define FARMANDCONQUER_SPATIAL_GRID_SYSTEM_HPP
#include "system.hpp"
#include "collision/spatial_grid.hpp"
#include "events/created_collidable_event.hpp"
#include "events/created_renderable_event.hpp"


class SpatialGridSystem : public System {
public:
    SpatialGridSystem(SpatialGrid *rendering_grid, SpatialGrid *physic_grid, entt::registry *registry, entt::dispatcher *dispatcher);

    void update(int elapsed) override;

private:
    SpatialGrid *rendering_grid_;
    SpatialGrid *physic_grid_;

    void clear_moving_entities() const;

    void register_moving_entities() const;

    void on_created_collidable(const CreatedCollidableEvent &event) const;

    void on_created_renderable(const CreatedRenderableEvent &event) const;
};


#endif //FARMANDCONQUER_SPATIAL_GRID_SYSTEM_HPP
