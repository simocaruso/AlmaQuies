//
// Created by simone on 24/11/25.
//

#ifndef FARMANDCONQUER_PLAYER_OCCLUSION_SYSTEM_HPP
#define FARMANDCONQUER_PLAYER_OCCLUSION_SYSTEM_HPP
#include "system.hpp"
#include "collision/spatial_grid.hpp"
#include "../components/render_component.hpp"

struct Data {
    Vec2 position;
    float radius;
    ColliderComponent bitmap_collider;
    Vec2 bitmap_center;
};

class OcclusionSystem : public System {
public:
    OcclusionSystem(entt::registry* registry, SpatialGrid* grid);

    void update(int elapsed) override;

private:
    SpatialGrid* grid_;

    Data get_entity_data(entt::entity entity) const;
};


#endif //FARMANDCONQUER_PLAYER_OCCLUSION_SYSTEM_HPP
