//
// Created by simone on 17/11/25.
//

#ifndef FARMANDCONQUER_MAP_TILES_GENERATOR_HPP
#define FARMANDCONQUER_MAP_TILES_GENERATOR_HPP
#include "map.hpp"
#include "FastNoiseLite/FastNoiseLite.hpp"

class MapTilesGenerator {
public:
    static Map generate(int width, int height);

private:
    static FastNoiseLite forest_noise_;
    static FastNoiseLite rock_noise_;
    static FastNoiseLite elevation_noise_;

    static void set_up_noise();
};


#endif //FARMANDCONQUER_MAP_TILES_GENERATOR_HPP
