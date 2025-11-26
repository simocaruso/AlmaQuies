//
// Created by simone on 13/11/25.
//

#include "collision_checker.hpp"

bool CollisionChecker::collide(const Vec2 &pos1, const ColliderComponent &c1,
                               const Vec2 &pos2, const ColliderComponent &c2) {
    return std::visit([&]<typename T0, typename T1>(T0 &&shape1, T1 &&shape2) -> bool {
        using S1 = std::decay_t<T0>;
        using S2 = std::decay_t<T1>;
        if constexpr (std::is_same_v<S1, CircleCollider> &&
                      std::is_same_v<S2, CircleCollider>) {
            return circle_vs_circle(pos1, shape1.radius,
                                    pos2, shape2.radius);
        } else if constexpr (std::is_same_v<S1, RectCollider> &&
                             std::is_same_v<S2, RectCollider>) {
            return rect_vs_rect(pos1, shape1.width, shape1.height,
                                pos2, shape2.width, shape2.height);
        } else if constexpr (
            std::is_same_v<S1, CircleCollider> &&
            std::is_same_v<S2, RectCollider>) {
            return circle_vs_rect(pos1, shape1.radius,
                                  pos2, shape2.width, shape2.height);
        } else if constexpr (
            std::is_same_v<S1, RectCollider> &&
            std::is_same_v<S2, CircleCollider>) {
            return circle_vs_rect(pos2, shape2.radius,
                                  pos1, shape1.width, shape1.height);
        }
        return false;
    }, c1.data, c2.data);
}

bool CollisionChecker::circle_vs_circle(const Vec2 &pos1, const int radius1,
                                        const Vec2 &pos2, const int radius2) {
    const float dx = pos1.x - pos2.x;
    const float dy = pos1.y - pos2.y;
    const float dist = dx * dx + dy * dy;
    const int radius_sum = radius1 + radius2;
    return dist <= radius_sum * radius_sum;
}

bool CollisionChecker::rect_vs_rect(const Vec2 &pos1, const int width1, const int height1,
                                    const Vec2 &pos2, const int width2, const int height2) {
    return std::abs(pos1.x - pos2.x) <= (width1 + width2) / 2.0f
           && std::abs(pos1.y - pos2.y) <= (height1 + height2) / 2.0f;
}

bool CollisionChecker::rect_vs_circle(const Vec2 &pos1, const int width1, const int height1,
                                      const Vec2 &pos2, const int radius2) {
    const float dx = std::abs(pos2.x - pos1.x);
    const float dy = std::abs(pos2.y - pos1.y);

    if (dx > (width1 / 2.0f + radius2)) return false;
    if (dy > (height1 / 2.0f + radius2)) return false;
    if (dx <= width1 / 2.0f) return true;
    if (dy <= height1 / 2.0f) return true;

    const float corner_dist_sq =
            (dx - width1 / 2.0f) * (dx - width1 / 2.0f) +
            (dy - height1 / 2.0f) * (dy - height1 / 2.0f);
    return corner_dist_sq <= (radius2 * radius2);
}

bool CollisionChecker::circle_vs_rect(const Vec2 &pos1, const int radius1,
                                      const Vec2 &pos2, const int width2, const int height2) {
    return rect_vs_circle(pos2, width2, height2, pos1, radius1);
}
