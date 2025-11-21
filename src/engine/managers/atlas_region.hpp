//
// Created by simone on 20/11/25.
//

#ifndef FARMANDCONQUER_RESOURCE_HPP
#define FARMANDCONQUER_RESOURCE_HPP

#include "../../util/vec_2.hpp"
#include "allegro5/allegro.h"

struct AtlasRegion {
    ALLEGRO_BITMAP* atlas;
    Vec2 position;
    int width = 0;
    int height = 0;
};

#endif //FARMANDCONQUER_RESOURCE_HPP
