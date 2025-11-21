//
// Created by simone on 06/11/25.
//

#include "renderer.hpp"
#include "../../../util/constants.hpp"
#include "../../managers/resource_manager.hpp"

Renderer::Renderer(ResourceManager* resource_manager) : resource_manager_(resource_manager) {
}

void Renderer::clear_to_color(const float r, const float g, const float b, const float a) {
    al_clear_to_color(al_map_rgba_f(r, g, b, a));
}

void Renderer::draw_scaled_bitmap(ALLEGRO_BITMAP* bitmap, const Vec2 &drawing_position,
                                  const float &destination_width,
                                  const float &destination_height) { // NOLINT(*-convert-member-functions-to-static)
    al_draw_scaled_bitmap(bitmap,
                          0, 0, (float) al_get_bitmap_width(bitmap), (float) al_get_bitmap_height(bitmap),
                          drawing_position.x, drawing_position.y, destination_width, destination_height, 0);
}

void Renderer::draw_resource(const std::string &sprite_id, const Vec2 &drawing_position,
                             const Vec2 &drawing_offset) const {
    auto resource = resource_manager_->get_resource(sprite_id);
    draw_bitmap_region(resource.atlas,
                   Vec2(resource.position.x, resource.position.y),
                   resource.width, resource.height,
                   drawing_position, drawing_offset);
}

void Renderer::draw_tile(const TileType &tile_type, const Vec2 &drawing_position, const Vec2 &drawing_offset) const {
    auto resource = resource_manager_->get_resource(tile_type);
    draw_bitmap_region(resource.atlas,
                       Vec2(resource.position.x, resource.position.y),
                       resource.width, resource.height,
                       drawing_position, drawing_offset);
}

void Renderer::draw_bitmap(ALLEGRO_BITMAP* bitmap, const Vec2 &drawing_position, const Vec2 &drawing_offset) {
    al_draw_bitmap(bitmap,
                   drawing_position.x - drawing_offset.x,
                   drawing_position.y - drawing_offset.y,
                   0);
}

void Renderer::draw_bitmap_region(ALLEGRO_BITMAP* bitmap, const Vec2 &region_position, const int region_width,
                                  const int region_height, const Vec2 &drawing_position, const Vec2 &drawing_offset) {
    al_draw_bitmap_region(bitmap,
                          region_position.x, region_position.y,
                          region_width, region_height,
                          drawing_position.x - drawing_offset.x,
                          drawing_position.y - drawing_offset.y,
                          0);
}


void Renderer::update_camera(ALLEGRO_TRANSFORM &trans, const Vec2 &position, const float zoom) {
    al_identity_transform(&trans);
    al_translate_transform(&trans, -position.x - BUFF_W / 2, -position.y - BUFF_H / 2);
    al_scale_transform(&trans, zoom, zoom);
    al_translate_transform(&trans, BUFF_W / 2, BUFF_H / 2);
    al_use_transform(&trans);
}
