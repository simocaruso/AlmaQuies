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

bool CollisionChecker::contains(const Vec2 &pos, const ColliderComponent &c, const Vec2 &c_pos) {
    return std::visit([&]<typename T>(T &&shape) -> bool {
        using S = std::decay_t<T>;
        if constexpr (std::is_same_v<S, CircleCollider>) {
            return circle_vs_circle(pos, 0, c_pos, shape.radius);
        } else if constexpr (std::is_same_v<S, RectCollider>) {
            return circle_vs_rect(pos, 0, c_pos, shape.width, shape.height);
        }
        return false;
    }, c.data);
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

float CollisionChecker::ray_vs_circle(const Ray &ray, const Vec2 &circle_pos, const int radius) {
    // Quadratic solution: |origin + t*dir - center|^2 = radius^2
    const Vec2 m = {ray.origin.x - circle_pos.x, ray.origin.y - circle_pos.y};
    const float b = m.x * ray.direction.x + m.y * ray.direction.y;
    const float c = m.x * m.x + m.y * m.y - static_cast<float>(radius * radius);

    // Ray starts outside and points away
    if (c > 0.0f && b > 0.0f) return -1.0f;

    const float discr = b * b - c;
    if (discr < 0.0f) return -1.0f;

    float t = -b - std::sqrt(discr);
    if (t < 0.0f) t = 0.0f; // ray origin inside circle
    if (t > ray.max_length) return -1.0f;

    return t;
}

float CollisionChecker::ray_vs_rect(const Ray &ray, const Vec2 &rect_pos, const int width, const int height) {
    // AABB slab method
    const float half_w = width / 2.0f;
    const float half_h = height / 2.0f;

    float t_min = 0.0f;
    float t_max = ray.max_length;

    // X axis
    if (std::abs(ray.direction.x) < 1e-6f) {
        if (ray.origin.x < rect_pos.x - half_w || ray.origin.x > rect_pos.x + half_w) return -1.0f;
    } else {
        float t1 = (rect_pos.x - half_w - ray.origin.x) / ray.direction.x;
        float t2 = (rect_pos.x + half_w - ray.origin.x) / ray.direction.x;
        if (t1 > t2) std::swap(t1, t2);
        t_min = std::max(t_min, t1);
        t_max = std::min(t_max, t2);
        if (t_min > t_max) return -1.0f;
    }

    // Y axis
    if (std::abs(ray.direction.y) < 1e-6f) {
        if (ray.origin.y < rect_pos.y - half_h || ray.origin.y > rect_pos.y + half_h) return -1.0f;
    } else {
        float t1 = (rect_pos.y - half_h - ray.origin.y) / ray.direction.y;
        float t2 = (rect_pos.y + half_h - ray.origin.y) / ray.direction.y;
        if (t1 > t2) std::swap(t1, t2);
        t_min = std::max(t_min, t1);
        t_max = std::min(t_max, t2);
        if (t_min > t_max) return -1.0f;
    }

    return t_min;
}

float CollisionChecker::raycast(const Ray &ray, const Vec2 &pos, const ColliderComponent &collider) {
    return std::visit([&]<typename T>(T &&shape) -> float {
        using S = std::decay_t<T>;
        if constexpr (std::is_same_v<S, CircleCollider>) {
            return ray_vs_circle(ray, pos, shape.radius);
        } else if constexpr (std::is_same_v<S, RectCollider>) {
            return ray_vs_rect(ray, pos, shape.width, shape.height);
        }
        return -1.0f;
    }, collider.data);
}
