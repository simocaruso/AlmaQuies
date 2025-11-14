//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_TRANSFORM_COMPONENT_HPP
#define FARMANDCONQUER_TRANSFORM_COMPONENT_HPP

#include "../../util/vec_2.hpp"

struct TransformComponent {
    Vec2 position;
    Vec2 prev_position;
    float angle = 0;
};

#endif //FARMANDCONQUER_TRANSFORM_COMPONENT_HPP
