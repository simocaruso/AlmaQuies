//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_UTIL_HPP
#define FARMANDCONQUER_UTIL_HPP

#include <cmath>
#include <limits>

void must_init(bool test, const char* description);
void error(bool test, const char* description);

template<typename T>
bool almost_equal(T a, T b) {
    T epsilon = std::numeric_limits<T>::epsilon();
    return std::abs(a - b) < epsilon;
}

#endif //FARMANDCONQUER_UTIL_HPP
