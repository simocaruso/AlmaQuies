//
// Created by simone on 06/11/25.
//

#include "display_target.hpp"

#include "bitmap_target.hpp"
#include "renderer.hpp"
#include "../../../util/constants.hpp"

DisplayTarget::DisplayTarget(Display* display): display_(display), render_buffer_(al_create_bitmap(BUFF_W, BUFF_H)), bitmap_target_(render_buffer_) {
}

void DisplayTarget::begin() {
    bitmap_target_.begin();
    Renderer::clear_to_color(.5f, .5f, .5f);
}

void DisplayTarget::end() {
    bitmap_target_.end();
    al_set_target_backbuffer(display_->get_display());
    Renderer::draw_scaled_bitmap(render_buffer_, Vec2(0, 0), display_->get_width(), display_->get_height());
    al_flip_display();
}
