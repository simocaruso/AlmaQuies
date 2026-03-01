//
// Created by simone on 19/11/25.
//

#ifndef ALMAQUIES_MAP_GENERATOR_HPP
#define ALMAQUIES_MAP_GENERATOR_HPP
#include "map.hpp"
#include "../entity_factory.hpp"

class MapGenerator {
public:
    static Map generate(int width, int height, entt::registry* registry, EntityFactory* entity_factory);
};


#endif //ALMAQUIES_MAP_GENERATOR_HPP
