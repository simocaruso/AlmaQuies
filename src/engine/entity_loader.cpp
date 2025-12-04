//
// Created by simone on 05/11/25.
//

#include "entity_loader.hpp"
#include <fmt/core.h>

#include "components/animation_component.hpp"
#include "components/collider_component.hpp"
#include "components/name_component.hpp"
#include "components/transform_component.hpp"
#include "components/render_component.hpp"
#include "components/player_tag.hpp"
#include "components/state_component.hpp"
#include "systems/events/created_collidable_event.hpp"
#include "systems/events/created_renderable_event.hpp"

EntityFileLoader::EntityFileLoader(entt::registry* registry, FileManager* file_manager,
                                   ResourceManager* resource_manager)
    : registry_(registry), file_manager_(file_manager), resource_manager_(resource_manager) {
    entities_config_.load(file_manager_->get_file("entities", "entities", "json"));
}

entt::entity EntityFileLoader::load_entity(const std::string &name, const Vec2 &position) const {
    const auto res = registry_->create();
    registry_->emplace<NameComponent>(res, name);
    registry_->emplace<TransformComponent>(res, position, position);
    if (entities_config_.has_field(fmt::format("{}.playerTag", name))) {
        registry_->emplace<PlayerTag>(res);
    }
    render(name, res);
    collision(name, res);
    animation(name, res);
    return res;
}

void EntityFileLoader::render(const std::string &name, const entt::entity &entity) const {
    auto base_field = fmt::format("{}.render", name);
    if (!entities_config_.has_field(base_field)) {
        return;
    }
    RenderComponent render_component;
    render_component.sprite = name;
    render_component.width = resource_manager_->get_resource_width(name);
    render_component.height = resource_manager_->get_resource_height(name);
    if (entities_config_.has_field(base_field)) {
        render_component.offset = vec2(fmt::format("{}.offset", base_field));
    }
    registry_->emplace<RenderComponent>(entity, render_component);
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
    }
}

void EntityFileLoader::animation(const std::string &name, const entt::entity &entity) const {
    auto base_field = fmt::format("{}.animations", name);
    if (!entities_config_.has_field(base_field)) {
        return;
    }
    AnimationComponent res;
    for (auto field: entities_config_.items(base_field)) {
        Animation anim;
        anim.name = field.key();
        anim.num_frames = field.value().at("frames");
        anim.frame_speed = field.value().at("frame_speed");
        res.animations.push_back(anim);
        res.active = anim;
    }
    registry_->emplace<AnimationComponent>(entity, res);
    registry_->emplace<StateComponent>(entity);
}

Vec2 EntityFileLoader::vec2(const std::string &field) const {
    Vec2 res;
    if (entities_config_.has_field(field)) {
        res.x = entities_config_.get<int>(fmt::format("{}.x", field));
        res.y = entities_config_.get<int>(fmt::format("{}.y", field));
    }
    return res;
}
