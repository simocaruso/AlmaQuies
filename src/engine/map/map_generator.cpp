//
// Created by simone on 19/11/25.
//

#include "map_generator.hpp"
#include "map_tiles_generator.hpp"
#include "map_resources_generator.hpp"
#include "../../util/constants.hpp"

Map MapGenerator::generate(const int width, const int height, entt::registry* registry, EntityFactory* entity_factory) {
    const MapTilesGenerator tiles{registry, entity_factory};
    auto res = tiles.generate(width, height, TILE_SIZE);
    MapResourcesGenerator::generate(&res, entity_factory);
    return res;
}
