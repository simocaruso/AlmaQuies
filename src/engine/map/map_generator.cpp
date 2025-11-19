//
// Created by simone on 19/11/25.
//

#include "map_generator.hpp"
#include "map_tiles_generator.hpp"
#include "map_resources_generator.hpp"


Map MapGenerator::generate(const int width, const int height, const EntityFactory* entity_factory) {
    auto res = MapTilesGenerator::generate(width, height);
    MapResourcesGenerator::generate(&res, entity_factory);
    return res;
}
