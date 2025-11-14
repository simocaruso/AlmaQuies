//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_COLLISION_CHECKER_HPP
#define FARMANDCONQUER_COLLISION_CHECKER_HPP

#include "../../../util/vec_2.hpp"
#include "../../components/transform_component.hpp"
#include "../../components/collider_component.hpp"

class CollisionChecker {
public:
    static bool collide(const TransformComponent &t1, const ColliderComponent &c1,
                        const TransformComponent &t2, const ColliderComponent &c2);

private:
    static bool circle_vs_circle(const Vec2 &pos1, int radius1, const Vec2 &pos2, int radius2);

    static bool rect_vs_rect(const Vec2 &pos1, int width1, int height1, const Vec2 &pos2, int width2, int height2);

    static bool rect_vs_circle(const Vec2 &pos1, int width1, int height1, const Vec2 &pos2, int radius2);

    static bool circle_vs_rect(const Vec2 &pos1, int radius1, const Vec2 &pos2, int width2, int height2);
};


#endif //FARMANDCONQUER_COLLISION_CHECKER_HPP
