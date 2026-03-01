//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_RENDERER_HPP
#define ALMAQUIES_RENDERER_HPP


#include "../../managers/resource_manager.hpp"
#include "../../../util/vec_2.hpp"

class Renderer {
public:
    explicit Renderer(ResourceManager* resource_manager);

    static void clear_to_color(float r, float g, float b, float a = 1);

    static void set_hold_bitmap(bool status);

    static bool get_hold_bimap_status();

    void draw_rect(Vec2 pos, int width, int height);

    static void use(ALLEGRO_SHADER * shader);

    static void draw_scaled_bitmap(ALLEGRO_BITMAP* bitmap, const Vec2 &drawing_position, const float &destination_width,
                                   const float &destination_height);

    void draw_resource(const std::string &sprite_id, const Vec2 &drawing_position, const Vec2 &drawing_offset) const;

    void draw_tile(const TileType &tile_type, const Vec2 &drawing_position, const Vec2 &drawing_offset) const;

    static void draw_bitmap(ALLEGRO_BITMAP* bitmap, const Vec2 &drawing_position, const Vec2 &drawing_offset);

    static void draw_bitmap_region(ALLEGRO_BITMAP* bitmap, const Vec2 &region_position, int region_width, int region_height,
                                   const Vec2 &drawing_position, const Vec2 &drawing_offset);

    static void update_camera(ALLEGRO_TRANSFORM &trans, const Vec2 &position, float zoom);

private:
    ResourceManager* resource_manager_;
};


#endif //ALMAQUIES_RENDERER_HPP
