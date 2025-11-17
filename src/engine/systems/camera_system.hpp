//
// Created by simone on 14/11/25.
//

#ifndef FARMANDCONQUER_CAMERA_SYSTEM_HPP
#define FARMANDCONQUER_CAMERA_SYSTEM_HPP

#include "system.hpp"
#include "events/zoom_command_event.hpp"


class CameraSystem : public System {
public:
    CameraSystem(entt::registry* registry, entt::dispatcher &dispatcher);

    void on_zoom(ZoomCommandEvent zoom_event);

    void update(int elapsed) override;
};


#endif //FARMANDCONQUER_CAMERA_SYSTEM_HPP
