//
// Created by simone on 17/11/25.
//

#include "map_tiles_generator.hpp"

FastNoiseLite MapTilesGenerator::forest_noise_;
FastNoiseLite MapTilesGenerator::rock_noise_;
FastNoiseLite MapTilesGenerator::elevation_noise_;

Map MapTilesGenerator::generate(const int width, const int height) {
    set_up_noise();
    Map res = {width, height};

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float f = forest_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;
            float r = rock_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;
            float e = elevation_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;

            TileType tile;
            if (r > 0.3f && e > 0.55f) {
                tile = Mountain;
            } else if (e < 0.38f) {
                tile = Water;
                if (e < 0.30f) tile = DeepWater;
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

void MapTilesGenerator::set_up_noise() {
    forest_noise_.SetSeed((int)time(NULL));
    elevation_noise_.SetSeed((int)time(NULL));
    rock_noise_.SetSeed((int)time(NULL));

    forest_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    forest_noise_.SetFrequency(0.1f);

    rock_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    rock_noise_.SetFrequency(0.02f);

    elevation_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    elevation_noise_.SetFrequency(0.1f);

    // Smooth variation
    forest_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    forest_noise_.SetFractalOctaves(3);
    forest_noise_.SetFractalGain(0.5f);
    forest_noise_.SetFractalLacunarity(1.8f);

    rock_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    rock_noise_.SetFractalOctaves(3);
    rock_noise_.SetFractalGain(0.5f);
    rock_noise_.SetFractalLacunarity(1.8f);

    elevation_noise_.SetFractalType(FastNoiseLite::FractalType_FBm);
    elevation_noise_.SetFractalOctaves(3);
    elevation_noise_.SetFractalGain(0.5f);
    elevation_noise_.SetFractalLacunarity(1.8f);
}
