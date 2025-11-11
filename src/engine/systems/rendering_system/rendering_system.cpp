//
// Created by simone on 06/11/25.
//

#include "rendering_system.hpp"
#include "renderer.hpp"
#include "display_target.hpp"
#include "../../components/transform_component.hpp"
#include "../../components/render_component.hpp"

RenderingSystem::RenderingSystem(entt::registry* registry, Renderer* renderer, Display* display)
        : System(registry), display_(display), renderer_(renderer) {
    render_buffer = al_create_bitmap(BUFF_W, BUFF_H);
}

void RenderingSystem::render() {
    BitmapTarget bitmap_target(render_buffer);
    renderer_->begin(bitmap_target);
    renderer_->clear_to_color(.5f, .5f, .5f);
    auto view = registry_->view<TransformComponent, RenderComponent>();
    for (auto entity: view) {
        auto &transform = view.get<TransformComponent>(entity);
        auto &render = view.get<RenderComponent>(entity);
        renderer_->draw_bitmap(render.sprite_id, transform.position, render.offset);
    }
    renderer_->end(bitmap_target);

    DisplayTarget display_target(display_);
    renderer_->begin(display_target);
    renderer_->draw_scaled_bitmap(render_buffer, Vec2(0, 0), display_->get_width(), display_->get_height());
    renderer_->end(display_target);
}
