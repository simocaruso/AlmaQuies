//
// Created by simone on 05/11/25.
//

#ifndef FARMANDCONQUER_RESOURCE_MANAGER_HPP
#define FARMANDCONQUER_RESOURCE_MANAGER_HPP


#include <string>
#include <allegro5/allegro.h>
#include <map>
#include "file_manager.hpp"
#include "../map/tile.hpp"

class ResourceManager {
public:
    explicit ResourceManager(FileManager* file_manager);

    ~ResourceManager();

    ALLEGRO_BITMAP* get_resource(const std::string &name);

    ALLEGRO_BITMAP* get_resource(const TileType &tile_type);

    int get_resource_width(const std::string & name);

    int get_resource_height(const std::string & name);

private:
    std::map<std::string, ALLEGRO_BITMAP*> bitmaps_;

    FileManager* file_manager_;

    void load_bitmap(const std::string &name);

    static std::string get_resource_name(const TileType &tile);
};


#endif //FARMANDCONQUER_RESOURCE_MANAGER_HPP
