//
// Created by simone on 05/11/25.
//

#include "entity_loader.hpp"

#include <fmt/core.h>
#include "components/transform_component.hpp"
#include "components/render_component.hpp"
#include "components/player_tag.hpp"

EntityLoader::EntityLoader(entt::registry* registry, FileManager* file_manager, ResourceManager* resource_manager)
    : registry_(registry), file_manager_(file_manager), resource_manager_(resource_manager) {
    entities_config_.load(file_manager_->get_file("entities", "entities", "json"));
}

entt::entity EntityLoader::load_entity(const std::string &name, const Vec2 &position) const {
    const auto res = registry_->create();
    registry_->emplace<TransformComponent>(res, position);
    registry_->emplace<RenderComponent>(res, name);

    if (entities_config_.has_field(fmt::format("{}.PlayerTag", name))) {
        registry_->emplace<PlayerTag>(res);
    }
    return res;
}
