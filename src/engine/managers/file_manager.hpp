//
// Created by simone on 05/11/25.
//

#ifndef ALMAQUIES_FILE_MANAGER_HPP
#define ALMAQUIES_FILE_MANAGER_HPP

#include <allegro5/allegro.h>

class FileManager {
public:
    FileManager() = default;

    ~FileManager() = default;

    const char* get_file(const char* dir_name, const char* file_name, const char* file_extension);

private:
    ALLEGRO_PATH* get_dir(const char* dir_name);
};


#endif //ALMAQUIES_FILE_MANAGER_HPP
