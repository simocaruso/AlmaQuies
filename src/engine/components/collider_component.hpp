//
// Created by simone on 13/11/25.
//

#ifndef ALMAQUIES_COLLIDER_COMPONENT_HPP
#define ALMAQUIES_COLLIDER_COMPONENT_HPP
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

#endif //ALMAQUIES_COLLIDER_COMPONENT_HPP
