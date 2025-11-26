//
// Created by simone on 05/11/25.
//

#include "entity_loader.hpp"
#include <fmt/core.h>

#include "components/collider_component.hpp"
#include "components/transform_component.hpp"
#include "components/render_component.hpp"
#include "components/player_tag.hpp"
#include "systems/events/created_collidable_event.hpp"
#include "systems/events/created_renderable_event.hpp"

EntityFileLoader::EntityFileLoader(entt::registry* registry, entt::dispatcher* dispatcher,
                                   FileManager* file_manager, ResourceManager* resource_manager)
    : registry_(registry), dispatcher_(dispatcher), file_manager_(file_manager), resource_manager_(resource_manager) {
    entities_config_.load(file_manager_->get_file("entities", "entities", "json"));
}

entt::entity EntityFileLoader::load_entity(const std::string &name, const Vec2 &position) const {
    const auto res = registry_->create();
    registry_->emplace<TransformComponent>(res, position, position);
    if (entities_config_.has_field(fmt::format("{}.playerTag", name))) {
        registry_->emplace<PlayerTag>(res);
    }
    render(name, res);
    collision(name, res);
    return res;
}

void EntityFileLoader::render(const std::string &name, const entt::entity &entity) const {
    auto base_field = fmt::format("{}.render", name);
    RenderComponent render_component;
    render_component.sprite_id = name;
    render_component.width = resource_manager_->get_resource_width(name);
    render_component.height = resource_manager_->get_resource_height(name);
    if (entities_config_.has_field(base_field)) {
        render_component.offset = vec2(fmt::format("{}.offset", base_field));
    }
    registry_->emplace<RenderComponent>(entity, render_component);
    dispatcher_->enqueue(CreatedRenderableEvent{
        entity,
        registry_->get<TransformComponent>(entity).position,
        registry_->get<RenderComponent>(entity)
    });
}

void EntityFileLoader::collision(const std::string &name, const entt::entity &entity) const {
    auto base_field = fmt::format("{}.collider", name);
    if (!entities_config_.has_field(base_field)) {
        return;
    }
    auto shape = entities_config_.get<std::string>(fmt::format("{}.shape", base_field));
    if (shape == "circle") {
        CircleCollider c;
        c.radius = entities_config_.get<int>(fmt::format("{}.radius", base_field));
        registry_->emplace<ColliderComponent>(entity, c);
    } else if (shape == "rect") {
        RectCollider r;
        r.width = entities_config_.get<int>(fmt::format("{}.width", base_field));
        r.height = entities_config_.get<int>(fmt::format("{}.height", base_field));
        registry_->emplace<ColliderComponent>(entity, r);
    } else {
        return;
    }
    dispatcher_->enqueue(CreatedCollidableEvent{
        entity,
        registry_->get<TransformComponent>(entity).position,
        registry_->get<ColliderComponent>(entity)
    });
}

Vec2 EntityFileLoader::vec2(const std::string &field) const {
    Vec2 res;
    if (entities_config_.has_field(field)) {
        res.x = entities_config_.get<int>(fmt::format("{}.x", field));
        res.y = entities_config_.get<int>(fmt::format("{}.y", field));
    }
    return res;
}
