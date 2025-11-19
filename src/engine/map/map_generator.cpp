//
// Created by simone on 17/11/25.
//

#include "map_generator.hpp"

MapGenerator::MapGenerator() {
    forest_noise_.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    forest_noise_.SetFrequency(0.02f);

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

Map MapGenerator::generate(const int width, const int height) const {
    Map res = {width, height};

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            float f = forest_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;
            float r = rock_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;
            float e = elevation_noise_.GetNoise(float(i), float(j)) * 0.5f + 0.5f;

            TileType tile;
            if (r > 0.55f && e > 0.4f) {
                tile = Mountain;
            } else if (e < 0.5f) {
                tile = Water;
            } else if (f > 0.5f) {
                tile = Forest;
            } else {
                tile = Grass;
            }
            res.add_tile(Vec2(i, j), tile);
        }
    }

    return res;
}
