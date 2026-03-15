//
// Created by simone on 17/11/25.
//

#ifndef ALMAQUIES_MAP_TILES_GENERATOR_HPP
#define ALMAQUIES_MAP_TILES_GENERATOR_HPP
#include "map.hpp"
#include "entt/entt.hpp"
#include "FastNoiseLite/FastNoiseLite.hpp"
#include "../entity_factory.hpp"

class MapTilesGenerator {
public:
    MapTilesGenerator(entt::registry* registry, EntityFactory* entity_factory);

    // Re-seeds the noise generators with a new random seed.
    static void reseed();

    // Generates tile type data only (no entities spawned).
    Map generate_tiles(int width, int height) const;

    // Spawns not_walkable_tile entities for all water tiles in the map.
    void spawn_entities(const Map &map, int tile_size) const;

private:
    static FastNoiseLite forest_noise_;
    static FastNoiseLite rock_noise_;
    static FastNoiseLite elevation_noise_;
    entt::registry* registry_;
    EntityFactory* entity_factory_;

    static void set_up_noise_params();

    void create_not_walkable_tile(int i, int j, int tile_size) const;
};


#endif //ALMAQUIES_MAP_TILES_GENERATOR_HPP
