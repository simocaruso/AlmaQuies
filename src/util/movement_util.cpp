//
// Created by simone on 03/03/26.
//

#include "movement_util.hpp"

Vec2 MovementUtil::get_direction(const Vec2 pos, const Vec2 target) {
    const Vec2 res = target - pos;
    return res.normalized();
}

Vec2 MovementUtil::get_direction(const Vec2 &speed) {
    return speed.normalized();
}
