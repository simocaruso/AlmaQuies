//
// Created by simone on 24/11/25.
//

#include "occlusion_system.hpp"

#include "../../util/util.hpp"
#include "../components/player_tag.hpp"
#include "../components/render_component.hpp"
#include "../components/transform_component.hpp"
#include "../components/outline_component.hpp"
#include "collision/collision_checker.hpp"
#include "../../../engine/spatial_grid.hpp"
#include "../../util/constants.hpp"


OcclusionSystem::OcclusionSystem(entt::registry* registry, SpatialGrid* grid)
    : System(registry), grid_(grid) {
}

void OcclusionSystem::update(int elapsed) {
    const auto player = registry_->view<PlayerTag>().front();
    auto player_data = get_entity_data(player);

    for (const auto &near_entity: grid_->query_nearby(player_data.position, player_data.radius)) {
        if (near_entity == player) continue;
        auto near_entity_data = get_entity_data(near_entity);
        if (near_entity_data.position.y < player_data.position.y) continue;
        if (CollisionChecker::collide(player_data.bitmap_center, player_data.bitmap_collider,
                                      near_entity_data.bitmap_center, near_entity_data.bitmap_collider)) {
            auto &outline_component = registry_->get_or_emplace<OutlineComponent>(player);
            outline_component.color = OCCLUDED_ENTITY_OUTLINE_COLOR;
            outline_component.is_active = true;
        }
    }
}

Data OcclusionSystem::get_entity_data(const entt::entity entity) const {
    const auto &position = registry_->get<TransformComponent>(entity).position;
    const auto &render = registry_->get<RenderComponent>(entity);
    RectCollider bitmap_collider = {render.width, render.height};
    Vec2 bitmap_center = position - render.offset;
    bitmap_center.x += render.width / 2.0f;
    bitmap_center.y += render.height / 2.0f;
    const float radius = compute_rect_radius(render.width, render.height);
    return {position, radius, ColliderComponent{bitmap_collider}, bitmap_center};
}
