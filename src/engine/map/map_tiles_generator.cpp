//
// Created by simone on 17/11/25.
//

#include "map_tiles_generator.hpp"
#include <random>

FastNoiseLite MapTilesGenerator::forest_noise_;
FastNoiseLite MapTilesGenerator::rock_noise_;
FastNoiseLite MapTilesGenerator::elevation_noise_;

MapTilesGenerator::MapTilesGenerator(entt::registry* registry, EntityFactory* entity_factory)
    : registry_(registry), entity_factory_(entity_factory) {
    set_up_noise_params();
    reseed();
}

void MapTilesGenerator::reseed() {
    std::random_device rd;
    const int seed = static_cast<int>(rd());
    forest_noise_.SetSeed(seed);
    elevation_noise_.SetSeed(seed + 1);
    rock_noise_.SetSeed(seed + 2);
}

Map MapTilesGenerator::generate_tiles(const int width, const int height) const {
    Map res = {width, height};

    // Create borders
    for (int i = 0; i < width; i++) {
        res.add_tile(Vec2(i, 0),          Water);
        res.add_tile(Vec2(i, height - 1), Water);
    }
    for (int j = 0; j < height; j++) {
        res.add_tile(Vec2(0, j),         Water);
        res.add_tile(Vec2(width - 1, j), Water);
    }

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            const float f = forest_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;
            const float r = rock_noise_.GetNoise(float(i), float(j))   * 0.5f + 0.5f;
            const float e = elevation_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;

            TileType tile;
            if (r > 0.3f && e > 0.55f) {
                tile = Mountain;
            } else if (e < 0.38f) {
                tile = e < 0.30f ? DeepWater : Water;
            } else if (f > 0.40f && e < 0.45f) {
                tile = Forest;
            } else {
                tile = Grass;
            }
            res.add_tile(Vec2(i, j), tile);
        }
    }

    return res;
}

void MapTilesGenerator::spawn_entities(const Map &map, const int tile_size) const {
    const int w = map.get_width_tiles();
    const int h = map.get_height_tiles();

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            const TileType t = map.get_tile_at_grid(i, j);
            if (t == Water || t == DeepWater)
                create_not_walkable_tile(i, j, tile_size);
        }
    }
}

void MapTilesGenerator::set_up_noise_params() {
    forest_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    forest_noise_.SetFrequency(0.1f);
    forest_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    forest_noise_.SetFractalOctaves(3);
    forest_noise_.SetFractalGain(0.5f);
    forest_noise_.SetFractalLacunarity(1.8f);

    rock_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    rock_noise_.SetFrequency(0.02f);
    rock_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    rock_noise_.SetFractalOctaves(3);
    rock_noise_.SetFractalGain(0.5f);
    rock_noise_.SetFractalLacunarity(1.8f);

    elevation_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    elevation_noise_.SetFrequency(0.1f);
    elevation_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    elevation_noise_.SetFractalOctaves(3);
    elevation_noise_.SetFractalGain(0.5f);
    elevation_noise_.SetFractalLacunarity(1.8f);
}

void MapTilesGenerator::create_not_walkable_tile(const int i, const int j, const int tile_size) const {
    entity_factory_->create_from_file("not_walkable_tile",
                                      Vec2((i + 0.5f) * tile_size, (j + 0.5f) * tile_size));
}
