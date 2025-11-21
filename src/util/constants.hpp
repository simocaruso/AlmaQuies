//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_CONSTANTS_HPP
#define FARMANDCONQUER_CONSTANTS_HPP


#include <string>

// Game
extern const char* GAME_NAME;
extern const float FPS_MILLIS;

// Display and buffer
extern const int DISP_H;
extern const int DISP_W;
extern const int BUFF_H;
extern const int BUFF_W;

// Collisions
extern const int COLLISION_SPATIAL_GRID_CELL_SIZE;

// Camera
extern const int CAMERA_ACCELERATION_STRENGTH;
extern const int CAMERA_DECELERATION_STRENGTH;
extern const int CAMERA_MAX_SPEED;
extern const float CAMERA_DEFAULT_ZOOM;
extern const float CAMERA_DEFAULT_ZOOM_SENSITIVITY;
extern const float CAMERA_MIN_ZOOM;
extern const float CAMERA_MAX_ZOOM;

// Map
extern const int TILE_SIZE;
extern const float FOREST_TREE_DENSITY;
extern const float MOUNTAIN_ROCK_DENSITY;

// Resources
extern const int ATLAS_SIZE;

#endif //FARMANDCONQUER_CONSTANTS_HPP
