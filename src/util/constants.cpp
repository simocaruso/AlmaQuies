//
// Created by simone on 31/10/25.
//

#include "constants.hpp"

const char* GAME_NAME = "Alma Quies";
const float FPS_MILLIS = 1.0f / 60.0f;

const int DISP_H = 720;
const int DISP_W = 1280;

const int BUFF_H = 720;
const int BUFF_W = 1280;

const int SPATIAL_GRID_CELL_SIZE = 64;

extern const int CAMERA_ACCELERATION_STRENGTH = 1000;
extern const int CAMERA_DECELERATION_STRENGTH = 1000;
extern const int CAMERA_MAX_SPEED = 600;
extern const float CAMERA_DEFAULT_ZOOM = 1.0f;
extern const float CAMERA_DEFAULT_ZOOM_SENSITIVITY = 0.05f;
extern const float CAMERA_MIN_ZOOM = 0.8f;
extern const float CAMERA_MAX_ZOOM = 2.0f;

extern const int TILE_SIZE = 64;
extern const float FOREST_TREE_DENSITY = 0.001f;
extern const float MOUNTAIN_ROCK_DENSITY = 0.0001f;

extern const int ATLAS_SIZE = 256;

extern const std::vector<float> OCCLUDED_ENTITY_OUTLINE_COLOR = {.0f, .0f, .0f, 1.0f};
extern const std::vector<float> SELECTED_ENTITY_OUTLINE_COLOR = {1.f, 1.f, .0f, 1.0f};

extern const float MOUSE_CLICK_RADIUS = 1.f;
