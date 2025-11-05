cmake_minimum_required(VERSION 3.26)
project(FarmAndConquer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FarmAndConquer
        src/main.cpp
        src/farm_and_conquer.hpp
        src/engine/engine.hpp
        src/engine/engine.cpp
        src/util/util.cpp
        src/util/util.hpp
        src/util/constants.hpp
        src/farm_and_conquer.cpp
        src/util/constants.cpp
        src/engine/systems/system.cpp
        src/engine/systems/system.hpp
        src/engine/display.cpp
        src/engine/display.hpp
        src/engine/systems/rendering_system.cpp
        src/engine/systems/rendering_system.hpp
        src/engine/managers/resource_manager.cpp
        src/engine/managers/resource_manager.hpp
        src/engine/managers/file_manager.cpp
        src/engine/managers/file_manager.hpp)

add_custom_target(
        CopyAssets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ./assets
        COMMENT "Copying assets directory to output"
)
add_dependencies(${PROJECT_NAME} CopyAssets)


include(FindPkgConfig)
pkg_check_modules(allegro-5 REQUIRED allegro-5)
pkg_check_modules(allegro_primitives-5 REQUIRED allegro_primitives-5)
pkg_check_modules(allegro_image-5 REQUIRED allegro_image-5)
pkg_check_modules(allegro_font-5 REQUIRED allegro_font-5)
pkg_check_modules(allegro_ttf-5 REQUIRED allegro_ttf-5)
pkg_check_modules(allegro_audio-5 REQUIRED allegro_audio-5)
pkg_check_modules(allegro_acodec-5 REQUIRED allegro_acodec-5)

include(FetchContent)

target_include_directories(FarmAndConquer PUBLIC
        ${allegro-5_INCLUDE_DIRS}
        ${allegro_primitives-5_INCLUDE_DIRS}
        ${allegro_image-5_INCLUDE_DIRS}
        ${allegro_font-5_INCLUDE_DIRS}
        ${allegro_ttf-5_INCLUDE_DIRS}
        ${allegro_audio-5_INCLUDE_DIRS}
        ${allegro_acodec-5_INCLUDE_DIRS}
)

target_include_directories(FarmAndConquer PRIVATE
        include
)

target_link_libraries(FarmAndConquer
        ${allegro-5_LIBRARIES}
        ${allegro_primitives-5_LIBRARIES}
        ${allegro_image-5_LIBRARIES}
        ${allegro_font-5_LIBRARIES}
        ${allegro_ttf-5_LIBRARIES}
        ${allegro_audio-5_LIBRARIES}
        ${allegro_acodec-5_LIBRARIES}
)