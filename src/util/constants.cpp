//
// Created by simone on 31/10/25.
//

#include "constants.hpp"
#include <numbers>

const char* GAME_NAME = "Alma Quies";
const float FPS_MILLIS = 1.0f / 60.0f;

const int DISP_H = 720;
const int DISP_W = 1280;

const int BUFF_H = 720;
const int BUFF_W = 1280;

const int SPATIAL_GRID_CELL_SIZE = 64;
const float AI_RAY_FRONT_LENGTH  = 80.0f;
const float AI_RAY_SIDE_LENGTH   = 50.0f;
const float AI_RAY_SIDE_ANGLE_1  = 30.0f * std::numbers::pi_v<float> / 180.0f;
const float AI_RAY_SIDE_ANGLE_2  = 80.0f * std::numbers::pi_v<float> / 180.0f;

const int CAMERA_ACCELERATION_STRENGTH = 1000;
const int CAMERA_DECELERATION_STRENGTH = 1000;
const int CAMERA_MAX_SPEED = 600;
const float CAMERA_DEFAULT_ZOOM = 1.0f;
const float CAMERA_DEFAULT_ZOOM_SENSITIVITY = 0.05f;
const float CAMERA_MIN_ZOOM = 0.8f;
const float CAMERA_MAX_ZOOM = 2.0f;

const int TILE_SIZE = 64;
const float FOREST_TREE_DENSITY = 0.001f;
const float MOUNTAIN_ROCK_DENSITY = 0.0001f;

const int ATLAS_SIZE = 256;

const std::vector<float> OCCLUDED_ENTITY_OUTLINE_COLOR = {.0f, .0f, .0f, 1.0f};
const std::vector<float> SELECTED_ENTITY_OUTLINE_COLOR = {1.f, 1.f, .0f, 1.0f};

const float MOUSE_CLICK_RADIUS = 1.f;
