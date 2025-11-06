//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_WORLD_HPP
#define FARMANDCONQUER_WORLD_HPP


#include "systems/rendering_system/rendering_system.hpp"
#include "entity_loader.hpp"

class World {
public:
    World(Display* display,
          Renderer* renderer,
          ResourceManager* resource_manager,
          FileManager* file_manager);

    void render();

private:
    Display* display_;
    Renderer* renderer_;
    ResourceManager* resource_manager_;
    FileManager* file_manager_;
    std::unique_ptr<entt::registry> registry_;
    std::unique_ptr<RenderingSystem> rendering_system_;
    std::unique_ptr<EntityLoader> entity_loader_;

};


#endif //FARMANDCONQUER_WORLD_HPP
