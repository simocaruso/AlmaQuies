//
// Created by simone on 13/11/25.
//

#ifndef ALMAQUIES_CREATED_RENDERABLE_EVENT_HPP
#define ALMAQUIES_CREATED_RENDERABLE_EVENT_HPP

#include "entt/entt.hpp"
#include "../../components/render_component.hpp"

struct CreatedRenderableEvent {
    entt::entity entity;
    Vec2 position;
    RenderComponent render;
};

#endif //ALMAQUIES_CREATED_RENDERABLE_EVENT_HPP
