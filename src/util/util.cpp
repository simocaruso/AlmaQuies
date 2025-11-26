//
// Created by simone on 31/10/25.
//

#include "util.hpp"
#include <iostream>
#include <allegro5/transformations.h>
#include "constants.hpp"
#include "vec_2.hpp"

void must_init(const bool test, const char* description) {
    if (test) return;
    printf("Couldn't initialize %s\n", description);
    exit(1);
}

void error(const bool test, const char* description) {
    if (test) return;
    printf("Error: %s\n", description);
    exit(1);
}

bool is_on_screen(const ALLEGRO_TRANSFORM &camera_transform, Vec2 top_left,
                  const int &width, const int &height) {
    Vec2 top_right = {top_left.x + width, top_left.y};
    Vec2 bottom_left = {top_left.x, top_left.y + height};
    Vec2 bottom_right = {top_left.x + width, top_left.y + height};

    al_transform_coordinates(&camera_transform, &top_left.x, &top_left.y);
    al_transform_coordinates(&camera_transform, &top_right.x, &top_right.y);
    al_transform_coordinates(&camera_transform, &bottom_left.x, &bottom_left.y);
    al_transform_coordinates(&camera_transform, &bottom_right.x, &bottom_right.y);


    const float minX = std::min({top_left.x, top_right.x, bottom_left.x, bottom_right.x});
    const float maxX = std::max({top_left.x, top_right.x, bottom_left.x, bottom_right.x});
    const float minY = std::min({top_left.y, top_right.y, bottom_left.y, bottom_right.y});
    const float maxY = std::max({top_left.y, top_right.y, bottom_left.y, bottom_right.y});

    if (maxX < 0 || minX > BUFF_W) return false;
    if (maxY < 0 || minY > BUFF_H) return false;
    return true;
}

float compute_rect_radius(const int width, const int height) {
    return std::sqrt((width * width + height * height) / 4.0f);
}

float compute_radius(const ColliderComponent &collider) {
    return std::visit([]<typename T>(T &&shape) -> float {
        using U = std::decay_t<decltype(shape)>;
        if constexpr (std::is_same_v<U, CircleCollider>) {
            return shape.radius;
        } else if constexpr (std::is_same_v<U, RectCollider>) {
            return compute_rect_radius(shape.width, shape.height);
        } else {
            return 0.0f;
        }
    }, collider.data);
}
