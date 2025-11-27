//
// Created by simone on 14/11/25.
//

#include "entity_factory.hpp"
#include "components/camera_component.hpp"
#include "components/transform_component.hpp"
#include "components/velocity_component.hpp"
#include "../util/constants.hpp"

EntityFactory::EntityFactory(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager)
    : registry_(registry) {
    entity_loader_ = std::make_unique<EntityFileLoader>(registry_, file_manager, resource_manager);
}

entt::entity EntityFactory::create_from_file(const std::string &name, const Vec2 &position) const {
    return entity_loader_->load_entity(name, position);
}

entt::entity EntityFactory::create_camera() const {
    const auto res = registry_->create();
    registry_->emplace<TransformComponent>(res);
    registry_->emplace<CameraComponent>(res);
    VelocityComponent velocity;
    velocity.acceleration_strength = CAMERA_ACCELERATION_STRENGTH;
    velocity.deceleration_strength = CAMERA_DECELERATION_STRENGTH;
    velocity.max_speed = CAMERA_MAX_SPEED;
    registry_->emplace<VelocityComponent>(res, velocity);
    return res;
}

entt::entity EntityFactory::create_basic_unit(const Vec2 &pos) const {
    const auto res = registry_->create();
    registry_->emplace<TransformComponent>(res, pos, pos);
    return res;
}
