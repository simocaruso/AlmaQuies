//
// Created by simone on 05/11/25.
//

#ifndef FARMANDCONQUER_RESOURCE_MANAGER_HPP
#define FARMANDCONQUER_RESOURCE_MANAGER_HPP


#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <map>
#include "file_manager.hpp"

class ResourceManager {
public:
    explicit ResourceManager(FileManager* file_manager);

    ~ResourceManager();

    ALLEGRO_BITMAP* get_resource(const std::string &name);

private:
    std::map<std::string, ALLEGRO_BITMAP*> bitmaps_;
    FileManager* file_manager_;

    void load_bitmap(const std::string &name);
};


#endif //FARMANDCONQUER_RESOURCE_MANAGER_HPP
