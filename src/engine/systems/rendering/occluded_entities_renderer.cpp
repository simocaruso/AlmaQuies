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

OccludedEntitiesRenderer::OccludedEntitiesRenderer(entt::registry *registry, Renderer *renderer,
                                                   FileManager *file_manager)
    : System(registry), renderer_(renderer),
      shader_(file_manager->get_file("shaders", "vertex", "glsl"),
              file_manager->get_file("shaders", "outline", "glsl")) {
}

void OccludedEntitiesRenderer::render() {
    shader_.use();
    auto view = registry_->view<VisibilityComponent, TransformComponent, RenderComponent>();
    for (const auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &visible = registry_->get<VisibilityComponent>(entity);
        auto &render = registry_->get<RenderComponent>(entity);
        shader_.set_float_vec("tex_size", std::vector{(float)ATLAS_SIZE, (float)ATLAS_SIZE});
        if (!visible.visible)
            renderer_->draw_resource(render.sprite, transform.position, render.offset);
    }
    al_use_shader((NULL));
}
