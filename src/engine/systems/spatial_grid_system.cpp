//
// Created by simone on 23/11/25.
//

#include "spatial_grid_system.hpp"

#include "../../util/util.hpp"
#include "../components/render_component.hpp"
#include "collision/collision_system.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"


SpatialGridSystem::SpatialGridSystem(SpatialGrid* rendering_grid, SpatialGrid* physic_grid, entt::registry* registry)
    : System(registry), rendering_grid_(rendering_grid), physic_grid_(physic_grid) {
}

void SpatialGridSystem::update(int elapsed) {
    clear_moving_entities();
    register_moving_entities();
}

void SpatialGridSystem::clear_moving_entities() const {
    for (auto &entity: registry_->view<TransformComponent, VelocityComponent>()) {
        auto entity_pos = registry_->get<TransformComponent>(entity).position;
        const auto collider = registry_->try_get<ColliderComponent>(entity);
        if (collider) {
            physic_grid_->remove(entity, entity_pos, compute_radius(*collider));
        }
        const auto rendering = registry_->try_get<RenderComponent>(entity);
        if (rendering) {
            rendering_grid_->remove(entity, entity_pos, compute_rect_radius(rendering->width, rendering->height));
        }
    }
}

void SpatialGridSystem::register_moving_entities() const {
    for (auto &entity: registry_->view<TransformComponent, VelocityComponent>()) {
        auto entity_pos = registry_->get<TransformComponent>(entity).position;
        const auto collider = registry_->try_get<ColliderComponent>(entity);
        if (collider) {
            physic_grid_->insert(entity, entity_pos, compute_radius(*collider));
        }
        const auto rendering = registry_->try_get<RenderComponent>(entity);
        if (rendering) {
            rendering_grid_->insert(entity, entity_pos, compute_rect_radius(rendering->width, rendering->height));
        }
    }
}

void SpatialGridSystem::on_created_collidable(entt::registry &registry, entt::entity entity) {
    auto position = registry.get<TransformComponent>(entity).position;
    auto collider = registry.get<ColliderComponent>(entity);
    physic_grid_->insert(entity, position, compute_radius(collider));
}

void SpatialGridSystem::on_created_renderable(entt::registry &registry, entt::entity entity) {
    auto position = registry.get<TransformComponent>(entity).position;
    auto render = registry.get<RenderComponent>(entity);
    rendering_grid_->insert(entity, position, compute_rect_radius(render.width, render.height));
}
