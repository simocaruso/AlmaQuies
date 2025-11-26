//
// Created by simone on 17/11/25.
//

#ifndef FARMANDCONQUER_MAP_RENDERER_HPP
#define FARMANDCONQUER_MAP_RENDERER_HPP
#include "../system.hpp"
#include "../../map/map.hpp"
#include "entt/entt.hpp"


class MapRenderer : public System {
public:
    MapRenderer(Map* map, entt::registry* registry, Renderer* renderer);

    ~MapRenderer();

    void create_chunks();

    void render() const;

private:
    Map* map_;
    Renderer* renderer_;
    std::vector<ALLEGRO_BITMAP*> chunks_;
    const int chunk_size_ = 16; // Size of the chunk in number of tiles
};


#endif //FARMANDCONQUER_MAP_RENDERER_HPP
