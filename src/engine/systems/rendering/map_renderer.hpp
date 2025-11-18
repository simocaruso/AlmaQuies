//
// Created by simone on 17/11/25.
//

#ifndef FARMANDCONQUER_MAP_RENDERER_HPP
#define FARMANDCONQUER_MAP_RENDERER_HPP
#include "../../map/map.hpp"


class MapRenderer {
public:
    MapRenderer(Map* map, Renderer* renderer);

    void create_chunks();

    void render() const;

private:
    Map* map_;
    Renderer* renderer_;
    std::vector<ALLEGRO_BITMAP*> chunks_;
    const int chunk_size_ = 16;
};


#endif //FARMANDCONQUER_MAP_RENDERER_HPP
