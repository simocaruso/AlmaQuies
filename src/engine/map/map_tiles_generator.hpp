//
// Created by simone on 17/11/25.
//

#ifndef FARMANDCONQUER_MAP_GENERATOR_HPP
#define FARMANDCONQUER_MAP_GENERATOR_HPP
#include "map.hpp"
#include "FastNoiseLite/FastNoiseLite.hpp"

class MapTilesGenerator {
public:
    MapTilesGenerator();

    Map generate(int width, int height) const;

private:
    FastNoiseLite forest_noise_;
    FastNoiseLite rock_noise_;
    FastNoiseLite elevation_noise_;
};


#endif //FARMANDCONQUER_MAP_GENERATOR_HPP
