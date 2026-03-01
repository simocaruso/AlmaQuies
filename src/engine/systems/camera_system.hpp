//
// Created by simone on 14/11/25.
//

#ifndef ALMAQUIES_CAMERA_SYSTEM_HPP
#define ALMAQUIES_CAMERA_SYSTEM_HPP

#include "system.hpp"
#include "events/zoom_command_event.hpp"


class CameraSystem : public System {
public:
    CameraSystem(entt::registry* registry, entt::dispatcher &dispatcher);

    void on_zoom(ZoomCommandEvent zoom_event);

    void update(int elapsed) override;
};


#endif //ALMAQUIES_CAMERA_SYSTEM_HPP
