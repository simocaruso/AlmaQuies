//
// Created by simone on 26/11/25.
//

#include "occluded_entities_renderer.hpp"
#include "../../components/visibility_compnent.hpp"
#include "../../components/render_component.hpp"
#include "../../components/transform_component.hpp"
#include "../../../util/constants.hpp"
#include "../../components/name_component.hpp"
#include "fmt/format.h"

OccludedEntitiesRenderer::OccludedEntitiesRenderer(entt::registry* registry, Renderer* renderer)
    : System(registry), renderer_(renderer) {
}

void OccludedEntitiesRenderer::render() {
    auto view = registry_->view<VisibilityComponent, TransformComponent, RenderComponent>();
    for (const auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &visible = registry_->get<VisibilityComponent>(entity);
        auto &render = view.get<RenderComponent>(entity);
        if (!visible.visible)
            renderer_->draw_resource(fmt::format("{}{}", registry_->get<NameComponent>(entity).name, BORDER_SUFFIX),
                                     transform.position, render.offset);
    }
}
