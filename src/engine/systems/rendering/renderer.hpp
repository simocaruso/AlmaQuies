//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_RENDERER_HPP
#define FARMANDCONQUER_RENDERER_HPP


#include "../../managers/resource_manager.hpp"
#include "render_target.hpp"
#include "../../../util/vec_2.hpp"

class Renderer {
public:
    explicit Renderer(ResourceManager* resource_manager);

    void begin(const RenderTarget &target);

    void end(const RenderTarget &target);

    void clear_to_color(float r, float g, float b, float a = 1);

    void draw_scaled_bitmap(ALLEGRO_BITMAP* bitmap, const Vec2 &drawing_position, const float &destination_width,
                            const float &destination_height);

    void draw_bitmap(const std::string &sprite_id, const Vec2 &drawing_position, const Vec2 &drawing_offset);

private:

    ResourceManager* resource_manager_;
};


#endif //FARMANDCONQUER_RENDERER_HPP
