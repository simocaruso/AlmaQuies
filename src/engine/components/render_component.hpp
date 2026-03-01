//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_RENDER_COMPONENT_HPP
#define ALMAQUIES_RENDER_COMPONENT_HPP

#include <string>
#include "../../util/vec_2.hpp"

struct RenderComponent {
    std::string sprite;
    int width, height;
    Vec2 offset;
};

#endif //ALMAQUIES_RENDER_COMPONENT_HPP
