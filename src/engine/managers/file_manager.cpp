//
// Created by simone on 05/11/25.
//

#include "file_manager.hpp"
#include <algorithm>

const char* FileManager::get_file(const char* dir_name, const char* file_name, const char* file_extension) {
    char res[512];

    memset(res, 0, 512);
    snprintf(res, 511, "%s.%s", file_name, file_extension);

    ALLEGRO_PATH* dir = get_dir(dir_name);
    ALLEGRO_PATH* path = al_create_path(res);
    al_rebase_path(dir, path);
    return al_path_cstr(path, '/');
}

ALLEGRO_PATH* FileManager::get_dir(const char* dir_name) { // NOLINT(*-convert-member-functions-to-static)
    ALLEGRO_PATH* dir;
    dir = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(dir, dir_name);
    return dir;
}