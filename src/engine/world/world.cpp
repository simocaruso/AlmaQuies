//
// Created by simone on 06/11/25.
//

#include "world.hpp"
#include "../managers/input_manager.hpp"
#include "../systems/camera_system.hpp"

World::World(Display* display, Renderer* renderer, ResourceManager* resource_manager, FileManager* file_manager,
             InputManager* input_manager) : display_(display), renderer_(renderer),
                                            resource_manager_(resource_manager),
                                            file_manager_(file_manager),
                                            input_manager_(input_manager) {
    registry_ = std::make_unique<entt::registry>();
    rendering_system_ = std::make_unique<RenderingSystem>(registry_.get(), renderer_, display_);
    dispatcher_ = std::make_unique<entt::dispatcher>();
    movement_system_ = std::make_unique<MovementSystem>(registry_.get(), *dispatcher_);
    input_system_ = std::make_unique<InputSystem>(registry_.get(), input_manager_, dispatcher_.get());
    collision_system_ = std::make_unique<CollisionSystem>(registry_.get(), *dispatcher_);
    entity_factory_ = std::make_unique<EntityFactory>(registry_.get(), dispatcher_.get(),
                                                      file_manager_, resource_manager_);
    camera_system_ = std::make_unique<CameraSystem>(registry_.get(), *dispatcher_);
    entity_factory_->create_from_file("blue", Vec2(100, 100));
    entity_factory_->create_from_file("tree", Vec2(150, 100));
    entity_factory_->create_camera();
}

void World::update(const int elapsed) const {
    dispatcher_->update();
    input_system_->update(elapsed);
    movement_system_->update(elapsed);
    collision_system_->update(elapsed);
}

void World::render() const {
    rendering_system_->render();
}
