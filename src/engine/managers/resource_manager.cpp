//
// Created by simone on 05/11/25.
//

#include "resource_manager.hpp"
#include "../../util/util.hpp"

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
    ALLEGRO_STATE state;
    al_store_state(&state, ALLEGRO_STATE_TARGET_BITMAP | ALLEGRO_STATE_BLENDER);
    std::string path = file_manager_->get_file("res", name.c_str(), "png");
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path.c_str());
    bitmaps_.insert({name, bitmap});
}

ALLEGRO_BITMAP* ResourceManager::get_resource(const std::string &name) {
    if (!bitmaps_.contains(name))
        load_bitmap(name);
    return bitmaps_.find(name)->second;
}