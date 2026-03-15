//
// Created by simone on 19/11/25.
//

#include "map_generator.hpp"
#include "map_tiles_generator.hpp"
#include "map_resources_generator.hpp"
#include "map_validator.hpp"
#include "../../util/constants.hpp"

Map MapGenerator::generate(const int width, const int height, entt::registry* registry, EntityFactory* entity_factory) {
    const MapTilesGenerator tiles{registry, entity_factory};

    Map map{width, height};
    do {
        MapTilesGenerator::reseed();
        map = tiles.generate_tiles(width, height);
    } while (!MapValidator::has_path(map));

    tiles.spawn_entities(map, TILE_SIZE);
    MapResourcesGenerator::generate(&map, entity_factory);
    return map;
}
