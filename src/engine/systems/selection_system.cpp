//
// Created by simone on 28/02/26.
//

#include "selection_system.hpp"

#include "../../util/constants.hpp"
#include "../components/input_state_component.hpp"
#include "../components/outline_component.hpp"
#include "../components/player_tag.hpp"
#include "collision/collision_checker.hpp"
#include "../components/transform_component.hpp"
#include "../components/render_component.hpp"
#include "../components/state_component.hpp"


SelectionSystem::SelectionSystem(entt::registry* registry, SpatialGrid* grid)
    : System(registry), grid_(grid) {
}

void SelectionSystem::update(int elapsed) {
    const auto input = registry_->ctx().get<InputStateComponent>();
    if (input.left_click) {
        clean_entities_states();
        select_entity();
    } else {
        maintain_selection();
    }
}

void SelectionSystem::select_entity() const {
    const auto input = registry_->ctx().get<InputStateComponent>();
    for (const auto entity: grid_->query_nearby(Vec2(input.mouse_x, input.mouse_y), MOUSE_CLICK_RADIUS)) {
        if (registry_->any_of<PlayerTag>(entity)) continue;
        auto entity_position = registry_->get<TransformComponent>(entity).position;
        const auto &render = registry_->get<RenderComponent>(entity);
        RectCollider bitmap_collider = {render.width, render.height};
        Vec2 bitmap_center = entity_position - render.offset;
        bitmap_center.x += render.width / 2.0f;
        bitmap_center.y += render.height / 2.0f;
        if (CollisionChecker::contains(Vec2(input.mouse_x, input.mouse_y), ColliderComponent{bitmap_collider},
                                       bitmap_center)) {
            auto &entity_outline = registry_->get_or_emplace<OutlineComponent>(entity);
            entity_outline.color = SELECTED_ENTITY_OUTLINE_COLOR;
            entity_outline.is_active = true;
            auto &state = registry_->get_or_emplace<StateComponent>(entity);
            state.is_selected = true;
            break;
        }
    }
}

void SelectionSystem::clean_entities_states() const {
    for (auto entity: registry_->view<StateComponent>()) {
        auto &state = registry_->get<StateComponent>(entity);
        if (state.is_selected) {
            state.is_selected = false;
        }
    }
}

void SelectionSystem::maintain_selection() const {
    for (auto entity: registry_->view<StateComponent>()) {
        if (registry_->get<StateComponent>(entity).is_selected) {
            auto &entity_outline = registry_->get_or_emplace<OutlineComponent>(entity);
            entity_outline.is_active = true;
        }
    }
}
