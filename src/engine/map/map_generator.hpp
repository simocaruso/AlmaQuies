//
// Created by simone on 19/11/25.
//

#ifndef FARMANDCONQUER_MAP_GENERATOR_HPP
#define FARMANDCONQUER_MAP_GENERATOR_HPP
#include "map.hpp"
#include "../entity_factory.hpp"

class MapGenerator {
public:
    static Map generate(int width, int height, const EntityFactory* entity_factory);
};


#endif //FARMANDCONQUER_MAP_GENERATOR_HPP
