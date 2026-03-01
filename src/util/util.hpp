//
// Created by simone on 31/10/25.
//

#ifndef ALMAQUIES_UTIL_HPP
#define ALMAQUIES_UTIL_HPP

#include <cmath>
#include <limits>
#include <allegro5/transformations.h>

#include "vec_2.hpp"
#include "../engine/components/collider_component.hpp"

void must_init(bool test, const char* description);

void error(bool test, const char* description);

bool is_on_screen(const ALLEGRO_TRANSFORM &camera_transform, Vec2 top_left,
                  const int &width, const int &height);

/* Compute the max influence radius a rect can have,
 * i.e. half of its diagonal.
 */
float compute_rect_radius(int width, int height);


/* Compute the max influence radius a rect can have */
float compute_radius(const ColliderComponent &collider);

template<typename T>
bool almost_equal(T a, T b) {
    T epsilon = std::numeric_limits<T>::epsilon();
    return std::abs(a - b) < epsilon;
}

#endif //ALMAQUIES_UTIL_HPP
