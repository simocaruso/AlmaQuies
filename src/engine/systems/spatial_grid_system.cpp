//
// Created by simone on 23/11/25.
//

#include "spatial_grid_system.hpp"

#include "../../util/util.hpp"
#include "../components/render_component.hpp"
#include "collision/collision_system.hpp"
#include "events/created_collidable_event.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"
#include "events/created_renderable_event.hpp"


SpatialGridSystem::SpatialGridSystem(SpatialGrid* rendering_grid, SpatialGrid* physic_grid, entt::registry* registry,
                                     entt::dispatcher* dispatcher)
    : System(registry), rendering_grid_(rendering_grid), physic_grid_(physic_grid) {
    dispatcher->sink<CreatedCollidableEvent>().connect<&SpatialGridSystem::on_created_collidable>(this);
    dispatcher->sink<CreatedRenderableEvent>().connect<&SpatialGridSystem::on_created_renderable>(this);
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

void SpatialGridSystem::on_created_collidable(const CreatedCollidableEvent &event) const {
    physic_grid_->insert(event.entity, event.position, compute_radius(event.collider));
}

void SpatialGridSystem::on_created_renderable(const CreatedRenderableEvent &event) const {
    rendering_grid_->insert(event.entity, event.position, compute_rect_radius(event.render.width, event.render.height));
}
