//
// Created by simone on 05/11/25.
//

#ifndef FARMANDCONQUER_ENTITY_LOADER_HPP
#define FARMANDCONQUER_ENTITY_LOADER_HPP


#include "managers/resource_manager.hpp"
#include "entt/entt.hpp"
#include "../util/vec_2.hpp"
#include "managers/json_reader.hpp"

class EntityFileLoader {
public:
    EntityFileLoader(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager);

    entt::entity load_entity(const std::string &name, const Vec2 &position) const;

private:
    JSONReader entities_config_;
    entt::registry* registry_;
    FileManager* file_manager_;
    ResourceManager* resource_manager_;

    void render(const std::string &name, const entt::entity &entity) const;

    void collision(const std::string &name, const entt::entity &entity) const;

    Vec2 vec2(const std::string &field) const;
};


#endif //FARMANDCONQUER_ENTITY_LOADER_HPP
