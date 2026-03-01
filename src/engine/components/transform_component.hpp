//
// Created by simone on 06/11/25.
//

#ifndef ALMAQUIES_TRANSFORM_COMPONENT_HPP
#define ALMAQUIES_TRANSFORM_COMPONENT_HPP

#include "../../util/vec_2.hpp"

struct TransformComponent {
    Vec2 position;
    Vec2 prev_position;
    float angle = 0;
};

#endif //ALMAQUIES_TRANSFORM_COMPONENT_HPP
