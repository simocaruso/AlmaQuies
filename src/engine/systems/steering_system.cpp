//
// Created by simone on 13/03/26.
//

#include "steering_system.hpp"
#include "../components/tags/ai_controlled_tag.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"
#include "../components/collider_component.hpp"
#include "collision/collision_checker.hpp"
#include "../../util/movement_util.hpp"
#include <cmath>
#include <array>
#include <numbers>

static constexpr float AVOIDANCE_STRENGTH = 800.0f;

static Vec2 rotate(const Vec2 &v, float angle) {
    const float cos_a = std::cos(angle);
    const float sin_a = std::sin(angle);
    return {v.x * cos_a - v.y * sin_a, v.x * sin_a + v.y * cos_a};
}

SteeringSystem::SteeringSystem(SpatialGrid* grid, entt::registry* registry)
    : System(registry), grid_(grid) {}

void SteeringSystem::update(int elapsed) {
    cast_rays_and_steer();
}

void SteeringSystem::update_rays(std::array<Ray, AI_RAY_COUNT> &rays, const Vec2 position, const Vec2 forward) const {
    rays[0] = {position, forward,                               AI_RAY_FRONT_LENGTH};
    rays[1] = {position, rotate(forward, -AI_RAY_SIDE_ANGLE_1), AI_RAY_SIDE_LENGTH};
    rays[2] = {position, rotate(forward,  AI_RAY_SIDE_ANGLE_1), AI_RAY_SIDE_LENGTH};
    rays[3] = {position, rotate(forward, -AI_RAY_SIDE_ANGLE_2), AI_RAY_SIDE_LENGTH};
    rays[4] = {position, rotate(forward,  AI_RAY_SIDE_ANGLE_2), AI_RAY_SIDE_LENGTH};
}

std::array<float, AI_RAY_COUNT> SteeringSystem::compute_min_hits(const std::array<Ray, AI_RAY_COUNT> &rays, const entt::entity entity) const {
    std::array<float, AI_RAY_COUNT> min_hit{};
    min_hit.fill(-1.0f);

    const auto nearby = grid_->query_nearby(rays[0].origin, AI_RAY_FRONT_LENGTH);
    for (const auto other: nearby) {
        if (other == entity) continue;
        if (!registry_->all_of<TransformComponent, ColliderComponent>(other)) continue;

        const auto &other_pos = registry_->get<TransformComponent>(other).position;
        const auto &other_col = registry_->get<ColliderComponent>(other);

        for (int i = 0; i < AI_RAY_COUNT; ++i) {
            const float hit = CollisionChecker::raycast(rays[i], other_pos, other_col);
            if (hit >= 0.0f && (min_hit[i] < 0.0f || hit < min_hit[i]))
                min_hit[i] = hit;
        }
    }
    return min_hit;
}

Vec2 SteeringSystem::compute_avoidance_force(const std::array<Ray, AI_RAY_COUNT> &rays,
                                             const std::array<float, AI_RAY_COUNT> &min_hit,
                                             const Vec2 &entity_pos, const Vec2 &forward) const {
    Vec2 force{0.0f, 0.0f};

    // Front ray: steer laterally toward the clearer side to avoid getting stuck
    if (min_hit[0] >= 0.0f) {
        // rays 1,3 are left (-angle); rays 2,4 are right (+angle)
        const float left_clearance  = (min_hit[1] < 0.0f ? rays[1].max_length : min_hit[1])
                                    + (min_hit[3] < 0.0f ? rays[3].max_length : min_hit[3]);
        const float right_clearance = (min_hit[2] < 0.0f ? rays[2].max_length : min_hit[2])
                                    + (min_hit[4] < 0.0f ? rays[4].max_length : min_hit[4]);

        const Vec2 lateral = right_clearance > left_clearance
                                 ? rotate(forward,  std::numbers::pi_v<float> / 2.0f)
                                 : rotate(forward, -std::numbers::pi_v<float> / 2.0f);

        const float strength = 1.0f - min_hit[0] / rays[0].max_length;
        force += lateral * (strength * AVOIDANCE_STRENGTH);
    }

    // Side rays: push away from the hit point
    for (int i = 1; i < AI_RAY_COUNT; ++i) {
        if (min_hit[i] < 0.0f) continue;
        const Vec2 hit_point = rays[i].origin + rays[i].direction * min_hit[i];
        const Vec2 away = (entity_pos - hit_point).normalized();
        const float strength = 1.0f - min_hit[i] / rays[i].max_length;
        force += away * (strength * AVOIDANCE_STRENGTH);
    }

    return force;
}

void SteeringSystem::cast_rays_and_steer() const {
    auto view = registry_->view<AIControlledTag, TransformComponent, VelocityComponent>();

    for (const auto entity: view) {
        auto &ai        = view.get<AIControlledTag>(entity);
        auto &transform = view.get<TransformComponent>(entity);
        auto &vel       = view.get<VelocityComponent>(entity);

        const Vec2 forward = MovementUtil::get_direction(vel.speed);
        if (forward.length() < 0.001f) continue;

        update_rays(ai.rays, transform.position, forward);

        const auto min_hit = compute_min_hits(ai.rays, entity);
        const Vec2 avoidance_force = compute_avoidance_force(ai.rays, min_hit, transform.position, forward);

        if (avoidance_force.length() > 0.001f) {
            vel.acceleration += avoidance_force;
            vel.active = true;
        }
    }
}
