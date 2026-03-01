//
// Created by simone on 07/11/25.
//

#ifndef ALMAQUIES_VELOCITY_COMPONENT_HPP
#define ALMAQUIES_VELOCITY_COMPONENT_HPP

#include "../../util/vec_2.hpp"

struct VelocityComponent {
    Vec2 speed;
    Vec2 direction;
    Vec2 acceleration;
    float acceleration_strength = 500.0f;
    float deceleration_strength = 400.0f;
    float max_speed = 200.0f;
    bool active = false;
};

#endif //ALMAQUIES_VELOCITY_COMPONENT_HPP
