//
// Created by simone on 06/11/25.
//

#include "rendering_system.hpp"
#include "renderer.hpp"
#include "display_target.hpp"

RenderingSystem::RenderingSystem(entt::registry* registry, Renderer* renderer,
                                 Display* display)
        : System(registry), display_(display), renderer_(renderer) {
    render_buffer = al_create_bitmap(BUFF_W, BUFF_H);
}

void RenderingSystem::update(int elapsed) {

}

void RenderingSystem::render() {
    BitmapTarget bitmap_target(render_buffer);
    renderer_->begin(bitmap_target);
    renderer_->clear_to_color(.5f, .5f, .5f);
    // TODO: render entities
    renderer_->end(bitmap_target);

    DisplayTarget display_target(display_);
    renderer_->begin(display_target);
    renderer_->draw_scaled_bitmap(render_buffer, Vec2(0, 0), display_->get_width(), display_->get_height());
    renderer_->end(display_target);
}
