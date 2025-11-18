//
// Created by simone on 05/11/25.
//

#include "resource_manager.hpp"
#include "../../util/util.hpp"
#include "allegro5/allegro_image.h"

ResourceManager::ResourceManager(FileManager* file_manager) {
    must_init(al_init_image_addon(), "image");
    this->file_manager_ = file_manager;
}

ResourceManager::~ResourceManager() {
    for (const auto &elem: bitmaps_) {
        al_destroy_bitmap(elem.second);
    }
}

void ResourceManager::load_bitmap(const std::string &name) { // NOLINT(*-convert-member-functions-to-static)
    al_set_new_bitmap_flags(ALLEGRO_MIPMAP | ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    ALLEGRO_STATE state;
    al_store_state(&state, ALLEGRO_STATE_TARGET_BITMAP | ALLEGRO_STATE_BLENDER);
    std::string path = file_manager_->get_file("assets", name.c_str(), "png");
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path.c_str());
    bitmaps_.insert({name, bitmap});
}

ALLEGRO_BITMAP* ResourceManager::get_resource(const std::string &name) {
    if (!bitmaps_.contains(name))
        load_bitmap(name);
    return bitmaps_.find(name)->second;
}

ALLEGRO_BITMAP* ResourceManager::get_resource(const TileType &tile_type) {
    return get_resource(get_resource_name(tile_type));
}

std::string ResourceManager::get_resource_name(const TileType &tile) {
    switch (tile) {
        case Grass:
            return "grass_tile";
            break;
        case Forest:
            return "grass_tile";
            break;
        case Mountain:
            return "mountain_tile";
            break;
        default:
            return "default_tile";
    }
}
