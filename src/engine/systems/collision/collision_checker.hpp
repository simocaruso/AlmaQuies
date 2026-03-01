//
// Created by simone on 13/11/25.
//

#ifndef ALMAQUIES_COLLISION_CHECKER_HPP
#define ALMAQUIES_COLLISION_CHECKER_HPP

#include "../../../util/vec_2.hpp"
#include "../../components/collider_component.hpp"

class CollisionChecker {
public:
    static bool collide(const Vec2 &pos1, const ColliderComponent &c1,
                        const Vec2 &pos2, const ColliderComponent &c2);

    static bool contains(const Vec2 &pos, const ColliderComponent &c, const Vec2 &c_pos);

private:
    static bool circle_vs_circle(const Vec2 &pos1, int radius1, const Vec2 &pos2, int radius2);

    static bool rect_vs_rect(const Vec2 &pos1, int width1, int height1, const Vec2 &pos2, int width2, int height2);

    static bool rect_vs_circle(const Vec2 &pos1, int width1, int height1, const Vec2 &pos2, int radius2);

    static bool circle_vs_rect(const Vec2 &pos1, int radius1, const Vec2 &pos2, int width2, int height2);

    static bool circle_vs_point(const Vec2 &pos1, int radius1, const Vec2 &pos2);

    static bool point_vs_circle(const Vec2 &pos1, const Vec2 &pos2, int radius2);

    static bool rect_vs_point(const Vec2 &pos1, int width1, int height1, const Vec2 &pos2);

    static bool point_vs_rect(const Vec2 &pos1, const Vec2 &pos2, int width2, int height2);
};


#endif //ALMAQUIES_COLLISION_CHECKER_HPP
