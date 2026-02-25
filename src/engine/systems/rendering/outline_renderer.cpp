//
// Created by simone on 26/11/25.
//

#include "outline_renderer.hpp"
#include "../../components/outline_component.hpp"
#include "../../components/render_component.hpp"
#include "../../components/transform_component.hpp"
#include "../../../util/constants.hpp"
#include "../../components/name_component.hpp"
#include "fmt/format.h"

OutlineRenderer::OutlineRenderer(entt::registry *registry, Renderer *renderer,
                                                   FileManager *file_manager)
    : System(registry), renderer_(renderer),
      shader_(file_manager->get_file("shaders", "vertex", "glsl"),
              file_manager->get_file("shaders", "outline", "glsl")) {
}

void OutlineRenderer::render() {
    shader_.use();
    auto view = registry_->view<OutlineComponent, TransformComponent, RenderComponent>();
    for (const auto entity: view) {
        auto &outline = registry_->get<OutlineComponent>(entity);
        auto &transform = view.get<TransformComponent>(entity);
        auto &render = registry_->get<RenderComponent>(entity);

        if (!outline.is_active) { continue; }

        shader_.set_float_vec("tex_size", std::vector{(float)ATLAS_SIZE, (float)ATLAS_SIZE});
        shader_.set_float_vec("outline_color", outline.color);
        renderer_->draw_resource(render.sprite, transform.position, render.offset);

        outline.is_active = false;
    }
    al_use_shader((NULL));
}
