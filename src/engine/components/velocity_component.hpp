//
// Created by simone on 07/11/25.
//

#ifndef FARMANDCONQUER_VELOCITY_COMPONENT_HPP
#define FARMANDCONQUER_VELOCITY_COMPONENT_HPP

#include "../../util/vec_2.hpp"

struct VelocityComponent {
    Vec2 speed;
    Vec2 direction;
    Vec2 acceleration;
    float acceleration_strength = 500.0f;
    float deceleration_strength = 800.0f;
    float max_speed = 200.0f;
    bool active = false;
};

#endif //FARMANDCONQUER_VELOCITY_COMPONENT_HPP
