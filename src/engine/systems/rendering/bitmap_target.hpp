//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_BITMAP_TARGET_HPP
#define FARMANDCONQUER_BITMAP_TARGET_HPP


#include <allegro5/allegro5.h>
#include "render_target.hpp"

class BitmapTarget : public RenderTarget {
public:
    explicit BitmapTarget(ALLEGRO_BITMAP* bitmap);

    void begin() const override;

    void end() const override {};

private:
    ALLEGRO_BITMAP* bitmap_;
};


#endif //FARMANDCONQUER_BITMAP_TARGET_HPP
