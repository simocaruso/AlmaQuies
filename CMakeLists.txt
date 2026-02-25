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
        src/engine/managers/resource_manager.cpp
        src/engine/managers/resource_manager.hpp
        src/engine/managers/file_manager.cpp
        src/engine/managers/file_manager.hpp
        src/engine/entity_loader.cpp
        src/engine/entity_loader.hpp
        src/util/vec_2.hpp
        src/engine/systems/rendering/render_target.hpp
        src/engine/systems/rendering/renderer.cpp
        src/engine/systems/rendering/renderer.hpp
        src/engine/systems/rendering/rendering_system.cpp
        src/engine/systems/rendering/rendering_system.hpp
        src/engine/systems/rendering/display_target.cpp
        src/engine/systems/rendering/display_target.hpp
        src/engine/systems/rendering/bitmap_target.cpp
        src/engine/systems/rendering/bitmap_target.hpp
        src/engine/components/transform_component.hpp
        src/engine/components/render_component.hpp
        src/engine/world.cpp
        src/engine/world.hpp
        src/engine/managers/input_manager.cpp
        src/engine/managers/input_manager.hpp
        src/engine/systems/input_system.cpp
        src/engine/systems/input_system.hpp
        src/engine/systems/events/move_command_event.hpp
        src/engine/components/player_tag.hpp
        src/engine/systems/movement_system.cpp
        src/engine/systems/movement_system.hpp
        src/engine/components/velocity_component.hpp
        src/engine/map/map.cpp
        src/engine/map/map.hpp
        src/engine/managers/json_reader.cpp
        src/engine/managers/json_reader.hpp
        src/engine/components/collider_component.hpp
        src/engine/systems/collision/collision_checker.cpp
        src/engine/systems/collision/collision_checker.hpp
        engine/spatial_grid.cpp
        engine/spatial_grid.hpp
        src/engine/systems/collision/collision_system.cpp
        src/engine/systems/collision/collision_system.hpp
        src/engine/systems/events/created_collidable_event.hpp
        src/engine/systems/collision/collision_resolver.cpp
        src/engine/systems/collision/collision_resolver.hpp
        src/engine/components/camera_component.hpp
        src/engine/systems/camera_system.cpp
        src/engine/systems/camera_system.hpp
        src/engine/entity_factory.cpp
        src/engine/entity_factory.hpp
        src/engine/systems/events/zoom_command_event.hpp
        src/engine/map/map_tiles_generator.cpp
        src/engine/map/map_tiles_generator.hpp
        src/engine/systems/rendering/map_renderer.cpp
        src/engine/systems/rendering/map_renderer.hpp
        src/engine/map/tile.hpp
        third_party/FastNoiseLite/FastNoiseLite.hpp
        src/engine/map/map_resources_generator.cpp
        src/engine/map/map_resources_generator.hpp
        src/util/random.hpp
        src/engine/map/map_generator.cpp
        src/engine/map/map_generator.hpp
        src/engine/managers/atlas_manager.cpp
        src/engine/managers/atlas_manager.hpp
        src/engine/managers/atlas_region.hpp
        src/engine/systems/spatial_grid_system.cpp
        src/engine/systems/spatial_grid_system.hpp
        src/engine/systems/occlusion_system.cpp
        src/engine/systems/occlusion_system.hpp
        src/engine/components/outline_component.hpp
        src/engine/systems/rendering/outline_renderer.cpp
        src/engine/systems/rendering/outline_renderer.hpp
        src/engine/systems/overlay_system.cpp
        src/engine/systems/overlay_system.hpp
        src/engine/overlay/window.cpp
        src/engine/overlay/window.hpp
        src/engine/overlay/window_factory.cpp
        src/engine/overlay/window_factory.hpp
        src/engine/systems/fps_system.cpp
        src/engine/systems/fps_system.hpp
        src/engine/systems/animation_system.cpp
        src/engine/systems/animation_system.hpp
        src/engine/components/animation_component.hpp
        src/engine/components/name_component.hpp
        src/engine/components/state_component.hpp
        src/engine/shader.cpp
        src/engine/shader.hpp
)

add_custom_target(
        CopyAssets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ./assets
        COMMENT "Copying assets directory to output"
)
add_dependencies(${PROJECT_NAME} CopyAssets)

add_custom_target(
        CopyShaders ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders ./shaders
        COMMENT "Copying shaders directory to output"
)
add_dependencies(${PROJECT_NAME} CopyShaders)

add_custom_target(
        CopyEntities ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/entities ./entities
        COMMENT "Copying entities directory to output"
)
add_dependencies(${PROJECT_NAME} CopyEntities)


include(FindPkgConfig)
pkg_check_modules(allegro-5 REQUIRED allegro-5)
pkg_check_modules(allegro_primitives-5 REQUIRED allegro_primitives-5)
pkg_check_modules(allegro_image-5 REQUIRED allegro_image-5)
pkg_check_modules(allegro_font-5 REQUIRED allegro_font-5)
pkg_check_modules(allegro_ttf-5 REQUIRED allegro_ttf-5)
pkg_check_modules(allegro_audio-5 REQUIRED allegro_audio-5)
pkg_check_modules(allegro_acodec-5 REQUIRED allegro_acodec-5)

include(FetchContent)

add_library(smol_atlas STATIC
        third_party/smol_atlas/smol_atlas.cpp
)

add_library(imgui STATIC
        third_party/imgui/imgui_impl_allegro5.cpp
        third_party/imgui/imgui.cpp
        third_party/imgui/imgui_draw.cpp
        third_party/imgui/imgui_widgets.cpp
        third_party/imgui/imgui_tables.cpp
        third_party/imgui/imgui_demo.cpp          # optional
        third_party/imgui/imgui_impl_allegro5.cpp
)

target_include_directories(FarmAndConquer PRIVATE
        third_party
)


target_compile_definitions(FarmAndConquer PRIVATE FMT_HEADER_ONLY=1)
target_link_libraries(FarmAndConquer
        ${allegro-5_LIBRARIES}
        ${allegro_primitives-5_LIBRARIES}
        ${allegro_image-5_LIBRARIES}
        ${allegro_font-5_LIBRARIES}
        ${allegro_ttf-5_LIBRARIES}
        ${allegro_audio-5_LIBRARIES}
        ${allegro_acodec-5_LIBRARIES}
        smol_atlas
        imgui
)