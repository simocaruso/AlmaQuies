//
// Created by simone on 06/11/25.
//

#include "world.hpp"
#include "managers/input_manager.hpp"
#include "map/map_generator.hpp"
#include "systems/camera_system.hpp"

World::World(Display *display, Renderer *renderer, ResourceManager *resource_manager, FileManager *file_manager,
             InputManager *input_manager) : display_(display), renderer_(renderer),
                                            resource_manager_(resource_manager),
                                            file_manager_(file_manager),
                                            input_manager_(input_manager) {
    registry_ = std::make_unique<entt::registry>();
    dispatcher_ = std::make_unique<entt::dispatcher>();
    add_system<MovementSystem>(MOVEMENT, registry_.get(), *dispatcher_);
    add_system<InputSystem>(INPUT, registry_.get(), input_manager_, dispatcher_.get());
    add_system<CollisionSystem>(COLLISION, registry_.get(), *dispatcher_);
    entity_factory_ = std::make_unique<EntityFactory>(registry_.get(), dispatcher_.get(),
                                                      file_manager_, resource_manager_);
    map_ = std::make_unique<Map>(MapGenerator::generate(128, 32, entity_factory_.get()));
    add_system<RenderingSystem>(RENDERING, map_.get(), registry_.get(), renderer_, display_);
    add_system<CameraSystem>(CAMERA, registry_.get(), *dispatcher_);
    entity_factory_->create_from_file("blue", Vec2(100, 100));
    entity_factory_->create_camera();
}

void World::update(const int elapsed) const {
    dispatcher_->update();
    for (auto &[n, system]: systems_) {
        system->update(elapsed);
    }
}

void World::render() {
    systems_[RENDERING]->render();
}
