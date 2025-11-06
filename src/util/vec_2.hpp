//
// Created by simone on 06/11/25.
//

#ifndef FARMANDCONQUER_VEC_2_HPP
#define FARMANDCONQUER_VEC_2_HPP


#include <valarray>

struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;

    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) const { return {x + other.x, y + other.y}; }
    Vec2 operator-(const Vec2& other) const { return {x - other.x, y - other.y}; }
    Vec2 operator*(float scalar) const { return {x * scalar, y * scalar}; }

    [[nodiscard]] float length() const { return std::sqrt(x * x + y * y); }
};

#endif //FARMANDCONQUER_VEC_2_HPP
