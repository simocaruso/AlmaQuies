//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_CREATED_RENDERABLE_EVENT_HPP
#define FARMANDCONQUER_CREATED_RENDERABLE_EVENT_HPP

#include "entt/entt.hpp"
#include "../../components/render_component.hpp"

struct CreatedRenderableEvent {
    entt::entity entity;
    Vec2 position;
    RenderComponent render;
};

#endif //FARMANDCONQUER_CREATED_RENDERABLE_EVENT_HPP
