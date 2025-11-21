//
// Created by simone on 20/11/25.
//

#ifndef FARMANDCONQUER_ATLAS_MANAGER_HPP
#define FARMANDCONQUER_ATLAS_MANAGER_HPP
#include <unordered_map>
#include <allegro5/bitmap.h>

#include "atlas_region.hpp"
#include "smol_atlas/smol_atlas.h"

class AtlasManager {
public:
    AtlasManager(int width, int height);

    ~AtlasManager();

    void add_sprite(const std::string &name, ALLEGRO_BITMAP* sprite);

    AtlasRegion get_region(const std::string &name) const;

    bool contains(const std::string &name) const;

private:
    ALLEGRO_BITMAP* bitmap_;
    smol_atlas_t* manager_;
    std::unordered_map<std::string, AtlasRegion> regions_;
};


#endif //FARMANDCONQUER_ATLAS_MANAGER_HPP
