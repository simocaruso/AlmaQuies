//
// Created by simone on 10/11/25.
//

#include "map.hpp"

#include "../../util/constants.hpp"
#include "../../util/util.hpp"

/**
 *
 * @param width The number of tiles in the X axis
 * @param height The number of tiles in the Y axis
 */
Map::Map(const int width, const int height) : width_(width), height_(height) {
    tiles_.resize(width * height);
}

/**
 * @param pos Coordinates in the grid space
 *              (0,0) (0,1) ...
 *              (1,0) (1,1) ...
 */
void Map::add_tile(const Vec2 pos, const TileType type) {
    tiles_[width_ * pos.y + pos.x] = type;
}

/**
 * @param pos Coordinates in the actual world space
 *            Tile1 is from (0,0) to (0,63)
 *            Tile2 is from (0,64) to (0,127)
 *            ...
 */
TileType Map::get_tile_at(const Vec2 &pos) const {
    const int x = std::floor(pos.x / TILE_SIZE);
    const int y = std::floor(pos.y / TILE_SIZE);

    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        error(false, "Tile position out of bounds");
    }

    return tiles_[width_ * y + x];
}

int Map::get_width() const {
    return width_;
}

int Map::get_height() const {
    return height_;
}

