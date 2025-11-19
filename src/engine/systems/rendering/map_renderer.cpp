//
// Created by simone on 17/11/25.
//

#include "map_renderer.hpp"
#include "bitmap_target.hpp"
#include "../../../util/constants.hpp"

MapRenderer::MapRenderer(Map* map, Renderer* renderer) : map_(map), renderer_(renderer) {
    create_chunks();
}

void MapRenderer::create_chunks() {
    const int map_width = map_->get_width_tiles();
    const int map_height = map_->get_height_tiles();

    const int chunks_x = std::ceil((float) map_width / chunk_size_);
    const int chunks_y = std::ceil((float) map_height / chunk_size_);

    chunks_.reserve(chunks_x * chunks_y);
    al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
    for (int chunk_x = 0; chunk_x < chunks_x; chunk_x++) {
        for (int chunk_y = 0; chunk_y < chunks_y; chunk_y++) {
            const int bitmap_width = map_->get_width_pixels();
            const int bitmap_height = map_->get_height_pixels();

            ALLEGRO_BITMAP* chunk = al_create_bitmap(bitmap_width, bitmap_height);
            BitmapTarget target(chunk);

            target.begin();
            for (int i = 0; i < chunk_size_; ++i) {
                for (int j = 0; j < chunk_size_; ++j) {
                    auto tile = map_->get_tile_at(Vec2(chunk_x * TILE_SIZE * chunk_size_ + i * TILE_SIZE, chunk_y * TILE_SIZE * chunk_size_ + j * TILE_SIZE));
                    renderer_->draw_bitmap(tile, Vec2(i * TILE_SIZE, j * TILE_SIZE), Vec2(0, 0));
                }
            }
            target.end();

            chunks_.push_back(chunk);
        }
    }
}

void MapRenderer::render() const {
    const int chunks_x = std::ceil((float) map_->get_width_tiles() / chunk_size_);
    const int chunks_y = std::ceil((float) map_->get_height_tiles() / chunk_size_);
    int chunk = 0;
    for (int i = 0; i < chunks_x; i++) {
        for (int j = 0; j < chunks_y; j++) {
            Renderer::draw_bitmap(chunks_[chunk],
                                  Vec2(i * TILE_SIZE * chunk_size_, j * chunk_size_ * TILE_SIZE),
                                  Vec2(0, 0));
            chunk++;
        }
    }
}
