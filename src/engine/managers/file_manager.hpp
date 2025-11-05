//
// Created by simone on 05/11/25.
//

#ifndef FARMANDCONQUER_FILE_MANAGER_HPP
#define FARMANDCONQUER_FILE_MANAGER_HPP

#include <cstdio>
#include <allegro5/allegro.h>

class FileManager {
public:
    FileManager() = default;
    ~FileManager() = default;
    const char* get_file(const char* dir_name, const char* file_name, const char* file_extension);
private:
    ALLEGRO_PATH* get_dir(const char* dir_name);
};



#endif //FARMANDCONQUER_FILE_MANAGER_HPP
