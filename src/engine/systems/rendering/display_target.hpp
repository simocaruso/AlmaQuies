//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_DISPLAY_TARGET_HPP
#define ALMAQUIES_DISPLAY_TARGET_HPP


#include "bitmap_target.hpp"
#include "render_target.hpp"
#include "../../display.hpp"

class DisplayTarget : public RenderTarget {
public:
    explicit DisplayTarget(Display* display);

    void begin() override;

    void end() override;

private:
    Display* display_;
    ALLEGRO_BITMAP* render_buffer_;
    BitmapTarget bitmap_target_;
};


#endif //ALMAQUIES_DISPLAY_TARGET_HPP
