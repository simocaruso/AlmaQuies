//
// Created by simone on 14/11/25.
//

#ifndef FARMANDCONQUER_CAMERA_COMPONENT_HPP
#define FARMANDCONQUER_CAMERA_COMPONENT_HPP

#include "../../util/constants.hpp"
#include "allegro5/allegro.h"

struct CameraComponent {
    ALLEGRO_TRANSFORM transform;
    float zoom = CAMERA_DEFAULT_ZOOM;
    float zoom_sensitivity = CAMERA_DEFAULT_ZOOM_SENSITIVITY;
    int scroll_direction = -1;
    float camera_min_zoom = CAMERA_MIN_ZOOM;
    float camera_max_zoom = CAMERA_MAX_ZOOM;
};

#endif //FARMANDCONQUER_CAMERA_COMPONENT_HPP