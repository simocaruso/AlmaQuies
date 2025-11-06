//
// Created by simone on 06/11/25.
//

#include "world.hpp"

World::World(Display* display, Renderer* renderer, ResourceManager* resource_manager, FileManager* file_manager) :
        display_(display), renderer_(renderer),
        resource_manager_(resource_manager),
        file_manager_(file_manager) {
    registry_ = std::make_unique<entt::registry>();
    rendering_system_ = std::make_unique<RenderingSystem>(registry_.get(), renderer_, display_);
    entity_loader_ = std::make_unique<EntityLoader>(registry_.get(), file_manager_, resource_manager_);
    entity_loader_->load_entity("blue", Vec2(100, 100));
}

void World::render() {
    rendering_system_->render();
}
