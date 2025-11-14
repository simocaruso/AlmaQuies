//
// Created by simone on 06/11/25.
//

#include "renderer.hpp"

Renderer::Renderer(ResourceManager *resource_manager) : resource_manager_(resource_manager) {
}

void Renderer::begin(const RenderTarget &target) {
    target.begin();
}

void Renderer::end(const RenderTarget &target) {
    target.end();
}

void Renderer::clear_to_color(float r, float g, float b, float a) {
    al_clear_to_color(al_map_rgba_f(r, g, b, a));
}

void Renderer::draw_scaled_bitmap(ALLEGRO_BITMAP *bitmap, const Vec2 &drawing_position,
                                  const float &destination_width,
                                  const float &destination_height) { // NOLINT(*-convert-member-functions-to-static)
    al_draw_scaled_bitmap(bitmap,
                          0, 0, (float) al_get_bitmap_width(bitmap), (float) al_get_bitmap_height(bitmap),
                          drawing_position.x, drawing_position.y, destination_width, destination_height, 0);
}

void Renderer::draw_bitmap(const std::string &sprite_id, const Vec2 &drawing_position, const Vec2 &drawing_offset) {
    al_draw_bitmap(resource_manager_->get_resource(sprite_id),
                   drawing_position.x - drawing_offset.x,
                   drawing_position.y - drawing_offset.y,
                   0);
}
