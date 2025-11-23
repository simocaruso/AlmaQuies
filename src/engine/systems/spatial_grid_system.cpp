//
// Created by simone on 23/11/25.
//

#include "spatial_grid_system.hpp"
#include "collision/collision_system.hpp"
#include "events/created_collidable_event.hpp"
#include "../components/transform_component.hpp"
#include "../components/velocity_component.hpp"


SpatialGridSystem::SpatialGridSystem(SpatialGrid *grid, entt::registry *registry, entt::dispatcher *dispatcher)
    : System(registry), grid_(grid) {
    dispatcher->sink<CreatedCollidableEvent>().connect<&SpatialGridSystem::on_created_collidable>(this);
}

void SpatialGridSystem::update(int elapsed) {
}

void SpatialGridSystem::clear_moving_entities() const {
    for (auto &entity: registry_->view<TransformComponent, VelocityComponent>()) {
        auto entity_pos = registry_->get<TransformComponent>(entity).position;
        grid_->remove(entity, entity_pos);
    }
}

void SpatialGridSystem::register_moving_entities() const {
    for (auto &entity: registry_->view<TransformComponent, VelocityComponent>()) {
        auto entity_pos = registry_->get<TransformComponent>(entity).position;
        grid_->insert(entity, entity_pos);
    }
}


void SpatialGridSystem::on_created_collidable(const CreatedCollidableEvent &event) const {
    grid_->insert(event.entity, event.position);
}
