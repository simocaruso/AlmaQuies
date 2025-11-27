//
// Created by simone on 05/11/25.
//

#include "resource_manager.hpp"
#include "../../util/util.hpp"
#include "allegro5/allegro_image.h"
#include "../../util/constants.hpp"

ResourceManager::ResourceManager(FileManager* file_manager) : atlas_manager_(ATLAS_SIZE, ATLAS_SIZE) {
    must_init(al_init_image_addon(), "image");
    this->file_manager_ = file_manager;
}

ResourceManager::~ResourceManager() = default;

void ResourceManager::load_bitmap(const std::string &name) { // NOLINT(*-convert-member-functions-to-static)
    ALLEGRO_STATE state;
    al_store_state(&state, ALLEGRO_STATE_TARGET_BITMAP | ALLEGRO_STATE_BLENDER);
    std::string path = file_manager_->get_file("assets", name.c_str(), "png");
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path.c_str());
    atlas_manager_.add_sprite(name, bitmap);
    al_destroy_bitmap(bitmap);
    al_restore_state(&state);
}

AtlasRegion ResourceManager::get_resource(const std::string &name) {
    if (!atlas_manager_.contains(name))
        load_bitmap(name);
    return atlas_manager_.get_region(name);
}

AtlasRegion ResourceManager::get_resource(const TileType &tile_type) {
    return get_resource(get_resource_name(tile_type));
}

int ResourceManager::get_resource_width(const std::string &name) {
    return get_resource(name).width;
}

int ResourceManager::get_resource_height(const std::string &name) {
    return get_resource(name).height;
}

std::string ResourceManager::get_resource_name(const TileType &tile) {
    switch (tile) {
        case Grass:
            return "grass_tile";
        case Forest:
            return "grass_tile";
        case Mountain:
            return "mountain_tile";
        case Water:
            return "water_tile";
        case DeepWater:
            return "deep_water_tile";
        default:
            return "default_tile";
    }
}
