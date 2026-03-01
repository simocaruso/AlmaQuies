//
// Created by simone on 14/11/25.
//

#ifndef ALMAQUIES_ENTITY_FACTORY_HPP
#define ALMAQUIES_ENTITY_FACTORY_HPP
#include <string>

#include "entity_loader.hpp"
#include "entt/entt.hpp"


class EntityFactory {
public:
    EntityFactory(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager);

    entt::entity create_from_file(const std::string &name, const Vec2 &position) const;

    entt::entity create_camera() const;

    entt::entity create_basic_unit(const Vec2 &pos) const;

private:
    entt::registry* registry_;
    std::unique_ptr<EntityFileLoader> entity_loader_;
    entt::dispatcher* dispatcher_;
};


#endif //ALMAQUIES_ENTITY_FACTORY_HPP
