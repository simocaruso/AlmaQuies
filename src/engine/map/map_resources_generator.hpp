//
// Created by simone on 19/11/25.
//

#ifndef FARMANDCONQUER_MAP_RESOURCES_GENERATOR_HPP
#define FARMANDCONQUER_MAP_RESOURCES_GENERATOR_HPP
#include "map.hpp"
#include "../entity_factory.hpp"

class MapResourcesGenerator {
public:
    static void generate(const Map* map, const EntityFactory* entity_factory);

private:
    static void generate_trees(const Map* map, const EntityFactory* entity_factory);

    static void generate_rocks(const Map* map, const EntityFactory* entity_factory);
};

#endif //FARMANDCONQUER_MAP_RESOURCES_GENERATOR_HPP
