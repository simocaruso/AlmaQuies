//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_RENDER_COMPONENT_HPP
#define FARMANDCONQUER_RENDER_COMPONENT_HPP

#include <string>
#include "../../util/vec_2.hpp"

struct RenderComponent {
    std::string sprite_id;
    int width, height;
    Vec2 offset;
};

#endif //FARMANDCONQUER_RENDER_COMPONENT_HPP
