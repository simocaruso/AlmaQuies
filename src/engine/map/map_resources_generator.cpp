//
// Created by simone on 19/11/25.
//

#include "map_resources_generator.hpp"

#include "../../util/constants.hpp"
#include "../../util/random.hpp"

void MapResourcesGenerator::generate(const Map* map, const EntityFactory* entity_factory) {
    generate_trees(map, entity_factory);
    generate_rocks(map, entity_factory);
}

void MapResourcesGenerator::generate_trees(const Map* map, const EntityFactory* entity_factory) {
    Random rng;
    int counter = 0;
    for (int i = 0; i < map->get_width_pixels(); i++) {
        for (int j = 0; j < map->get_height_pixels(); j++) {
            if (map->get_tile_at(Vec2(i, j)) == Forest) {
                if (rng.floatInRange(0.0, 1.0) < FOREST_TREE_DENSITY) {
                    entity_factory->create_from_file("tree", Vec2(i, j));
                    counter++;
                }
            }
        }
    }
    printf("Generated %d trees\n", counter);
}

void MapResourcesGenerator::generate_rocks(const Map* map, const EntityFactory* entity_factory) {
    Random rng;
    int counter = 0;
    for (int i = 0; i < map->get_width_pixels(); i++) {
        for (int j = 0; j < map->get_height_pixels(); j++) {
            if (map->get_tile_at(Vec2(i, j)) == Mountain) {
                if (rng.floatInRange(0.0, 1.0) < MOUNTAIN_ROCK_DENSITY) {
                    entity_factory->create_from_file("rock", Vec2(i, j));
                    counter++;
                }
            }
        }
    }
    printf("Generated %d rocks\n", counter);
}
