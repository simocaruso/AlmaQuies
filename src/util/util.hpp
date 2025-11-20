//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_UTIL_HPP
#define FARMANDCONQUER_UTIL_HPP

#include <cmath>
#include <limits>
#include <allegro5/transformations.h>

#include "vec_2.hpp"

void must_init(bool test, const char* description);

void error(bool test, const char* description);

bool is_on_screen(const ALLEGRO_TRANSFORM &camera_transform, Vec2 top_left,
                  const int &width, const int &height);

template<typename T>
bool almost_equal(T a, T b) {
    T epsilon = std::numeric_limits<T>::epsilon();
    return std::abs(a - b) < epsilon;
}

#endif //FARMANDCONQUER_UTIL_HPP
