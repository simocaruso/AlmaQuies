//
// Created by simone on 13/03/26.
//

#ifndef ALMAQUIES_RAY_HPP
#define ALMAQUIES_RAY_HPP

#include "../../../util/vec_2.hpp"

struct Ray {
    Vec2 origin;
    Vec2 direction; // normalized
    float max_length;
};

#endif //ALMAQUIES_RAY_HPP
