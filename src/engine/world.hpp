//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_WORLD_HPP
#define FARMANDCONQUER_WORLD_HPP


#include "systems/rendering/rendering_system.hpp"
#include "entity_loader.hpp"
#include "managers/input_manager.hpp"
#include "systems/input_system.hpp"
#include "systems/collision/collision_system.hpp"
#include "entity_factory.hpp"
#include "map/map.hpp"


class World {
public:
    World(Display *display, Renderer *renderer, ResourceManager *resource_manager,
          FileManager *file_manager, InputManager *input_manager);

    void render();

    template<typename T, typename... Args>
    T &add_system(const SystemType &type, Args &&... args) {
        auto system = std::make_unique<T>(std::forward<Args>(args)...);
        T &ref = *system;
        systems_[type] = std::move(system);
        return ref;
    }

    void update(int elapsed) const;

private:
    Display *display_;
    Renderer *renderer_;
    ResourceManager *resource_manager_;
    FileManager *file_manager_;
    InputManager *input_manager_;
    std::unique_ptr<entt::registry> registry_;
    std::unique_ptr<entt::dispatcher> dispatcher_;
    std::unique_ptr<EntityFactory> entity_factory_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<SpatialGrid> physic_spatial_grid_;
    std::unique_ptr<SpatialGrid> rendering_spatial_grid_;
    std::unordered_map<SystemType, std::unique_ptr<System> > systems_;
};


#endif //FARMANDCONQUER_WORLD_HPP
