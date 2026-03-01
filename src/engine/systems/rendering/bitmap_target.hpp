//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_BITMAP_TARGET_HPP
#define ALMAQUIES_BITMAP_TARGET_HPP


#include <allegro5/allegro5.h>
#include "render_target.hpp"

class BitmapTarget : public RenderTarget {
public:
    explicit BitmapTarget(ALLEGRO_BITMAP* bitmap);

    void begin() override;

    void end() override;

private:
    ALLEGRO_BITMAP* bitmap_;
    ALLEGRO_BITMAP* curr_target_{};
};


#endif //ALMAQUIES_BITMAP_TARGET_HPP
