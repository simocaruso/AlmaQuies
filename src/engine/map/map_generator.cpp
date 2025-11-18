//
// Created by simone on 17/11/25.
//

#include "map_generator.hpp"

Map MapGenerator::generate(const int width, const int height) {
    Map res = {width, height};

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            res.add_tile(Vec2(i, j), Grass);
        }
    }

    return res;
}
