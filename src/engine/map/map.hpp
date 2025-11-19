//
// Created by simone on 10/11/25.
//

#ifndef FARMANDCONQUER_MAP_HPP
#define FARMANDCONQUER_MAP_HPP

#include "tile.hpp"
#include "../systems/rendering/renderer.hpp"


class Map {
public:
    Map(int width_tiles, int height_tiles);

    void add_tile(Vec2 pos, TileType type);

    TileType get_tile_at(const Vec2 &pos) const;

    int get_width_tiles() const;

    int get_height_tiles() const;

    int get_width_pixels() const;

    int get_height_pixels() const;

private:
    int width_tiles_;
    int height_tiles_;
    std::vector<TileType> tiles_;
};


#endif //FARMANDCONQUER_MAP_HPP
