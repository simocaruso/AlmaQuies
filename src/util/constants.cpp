//
// Created by simone on 31/10/25.
//

#include "constants.hpp"

const char* GAME_NAME = "Farm And Conquer";
const float FPS_MILLIS = 1000 / 60.0f;

const int DISP_H = 720;
const int DISP_W = 1280;

const int BUFF_H = 720;
const int BUFF_W = 1280;

const int COLLISION_SPATIAL_GRID_CELL_SIZE = 64;

extern const int CAMERA_ACCELERATION_STRENGTH = 1000;
extern const int CAMERA_DECELERATION_STRENGTH = 1000;
extern const int CAMERA_MAX_SPEED = 400;
extern const float CAMERA_DEFAULT_ZOOM = 1.0f;
extern const float CAMERA_DEFAULT_ZOOM_SENSITIVITY = 0.05f;
extern const float CAMERA_MIN_ZOOM = 0.8f;
extern const float CAMERA_MAX_ZOOM = 2.0f;
