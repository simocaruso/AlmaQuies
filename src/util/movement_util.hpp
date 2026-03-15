//
// Created by simone on 03/03/26.
//

#ifndef FARMANDCONQUER_MOVEMENT_UTIL_HPP
#define FARMANDCONQUER_MOVEMENT_UTIL_HPP
#include "vec_2.hpp"


class MovementUtil {
public:
    static Vec2 get_direction(Vec2 pos, Vec2 target);

    static Vec2 get_direction(const Vec2 &speed);
};


#endif //FARMANDCONQUER_MOVEMENT_UTIL_HPP
