//
// Created by simone on 16/11/25.
//

#ifndef FARMANDCONQUER_ZOOM_COMMAND_EVENT_HPP
#define FARMANDCONQUER_ZOOM_COMMAND_EVENT_HPP

#include "entt/entt.hpp"

struct ZoomCommandEvent {
    entt::entity camera;
    int zoom_factor;
};

#endif //FARMANDCONQUER_ZOOM_COMMAND_EVENT_HPP
