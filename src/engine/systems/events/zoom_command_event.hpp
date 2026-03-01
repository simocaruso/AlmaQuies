//
// Created by simone on 16/11/25.
//

#ifndef ALMAQUIES_ZOOM_COMMAND_EVENT_HPP
#define ALMAQUIES_ZOOM_COMMAND_EVENT_HPP

#include "entt/entt.hpp"

struct ZoomCommandEvent {
    entt::entity camera;
    int zoom_factor;
};

#endif //ALMAQUIES_ZOOM_COMMAND_EVENT_HPP
