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

    Map generate(int width, int height, int tile_size) const;

private:
    static FastNoiseLite forest_noise_;
    static FastNoiseLite rock_noise_;
    static FastNoiseLite elevation_noise_;
    entt::registry* registry_;
    EntityFactory* entity_factory_;

    static void set_up_noise();
};


#endif //ALMAQUIES_MAP_TILES_GENERATOR_HPP
