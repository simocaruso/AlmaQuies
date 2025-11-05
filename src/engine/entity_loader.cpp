//
// Created by simone on 05/11/25.
//

#include "entity_loader.hpp"

EntityLoader::EntityLoader(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager)
        : registry_(registry), file_manager_(file_manager), resource_manager_(resource_manager) {

}

entt::entity EntityLoader::load_from_file(const std::string &name) {
    auto res = registry_->create();
    return res;
}
