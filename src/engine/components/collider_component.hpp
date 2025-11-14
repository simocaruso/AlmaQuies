//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_COLLIDER_COMPONENT_HPP
#define FARMANDCONQUER_COLLIDER_COMPONENT_HPP
#include <variant>


struct CircleCollider {
    int radius;
};

struct RectCollider {
    int width;
    int height;
};

using ColliderData = std::variant<CircleCollider, RectCollider>;

struct ColliderComponent {
    ColliderData data;
};

#endif //FARMANDCONQUER_COLLIDER_COMPONENT_HPP
