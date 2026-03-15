//
// Created by simone on 13/03/26.
//

#ifndef ALMAQUIES_STEERING_SYSTEM_HPP
#define ALMAQUIES_STEERING_SYSTEM_HPP

#include "system.hpp"
#include "../../../engine/spatial_grid.hpp"
#include "collision/ray.hpp"
#include "../../util/constants.hpp"

class SteeringSystem : public System {
public:
    SteeringSystem(SpatialGrid* grid, entt::registry* registry);

    void update(int elapsed) override;

private:
    SpatialGrid* grid_;

    void update_rays(std::array<Ray, AI_RAY_COUNT> &rays, Vec2 position, Vec2 forward) const;

    std::array<float, AI_RAY_COUNT> compute_min_hits(const std::array<Ray, AI_RAY_COUNT> &rays, entt::entity entity) const;

    Vec2 compute_avoidance_force(const std::array<Ray, AI_RAY_COUNT> &rays, const std::array<float, AI_RAY_COUNT> &min_hit, const Vec2 &entity_pos, const Vec2 &forward) const;

    void cast_rays_and_steer() const;
};

#endif //ALMAQUIES_STEERING_SYSTEM_HPP
