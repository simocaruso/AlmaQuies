//
// Created by simone on 05/11/25.
//

#include "entity_loader.hpp"

#include <fmt/core.h>
#include "components/transform_component.hpp"
#include "components/render_component.hpp"
#include "components/player_tag.hpp"

EntityLoader::EntityLoader(entt::registry *registry, FileManager *file_manager, ResourceManager *resource_manager)
    : registry_(registry), file_manager_(file_manager), resource_manager_(resource_manager) {
    entities_config_.load(file_manager_->get_file("entities", "entities", "json"));
}

entt::entity EntityLoader::load_entity(const std::string &name, const Vec2 &position) const {
    const auto res = registry_->create();
    registry_->emplace<TransformComponent>(res, position);
    if (entities_config_.has_field(fmt::format("{}.playerTag", name))) {
        registry_->emplace<PlayerTag>(res);
    }
    render(name, res);
    return res;
}

void EntityLoader::render(const std::string &name, const entt::entity &entity) const {
    auto base_field = fmt::format("{}.render", name);
    RenderComponent render_component;
    render_component.sprite_id = name;
    if (entities_config_.has_field(base_field)) {
        render_component.offset = vec2(fmt::format("{}.offset", base_field));
    }
    registry_->emplace<RenderComponent>(entity, render_component);
}

Vec2 EntityLoader::vec2(const std::string &field) const {
    Vec2 res;
    if (entities_config_.has_field(field)) {
        res.x = entities_config_.get<int>(fmt::format("{}.x", field));
        res.y = entities_config_.get<int>(fmt::format("{}.y", field));
    }
    return res;
}
