//
// Created by simone on 10/11/25.
//

#ifndef FARMANDCONQUER_MAP_HPP
#define FARMANDCONQUER_MAP_HPP

#include "tile.hpp"
#include "../systems/rendering/renderer.hpp"


class Map {
public:
    Map(int width, int height);

    void add_tile(Vec2 pos, TileType type);

    TileType get_tile_at(const Vec2 &pos) const;

    int get_width() const;

    int get_height() const;

private:
    int width_;
    int height_;
    std::vector<TileType> tiles_;
};


#endif //FARMANDCONQUER_MAP_HPP
