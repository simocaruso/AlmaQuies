//
// Created by simone on 05/11/25.
//

#ifndef FARMANDCONQUER_ENTITY_LOADER_HPP
#define FARMANDCONQUER_ENTITY_LOADER_HPP


#include "managers/resource_manager.hpp"
#include "entt/entt.hpp"
#include "../util/vec_2.hpp"

class EntityLoader {
public:
    EntityLoader(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager);

    entt::entity load_entity(const std::string &name, const Vec2 &position);

private:
    entt::registry* registry_;
    FileManager* file_manager_;
    ResourceManager* resource_manager_;
};


#endif //FARMANDCONQUER_ENTITY_LOADER_HPP
