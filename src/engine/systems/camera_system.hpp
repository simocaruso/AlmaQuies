//
// Created by simone on 14/11/25.
//

#ifndef ALMAQUIES_CAMERA_SYSTEM_HPP
#define ALMAQUIES_CAMERA_SYSTEM_HPP

#include "system.hpp"

class CameraSystem : public System {
public:
    explicit CameraSystem(entt::registry* registry);

    void update(int elapsed) override;

private:
    void handle_input(entt::entity camera) const;

    void handle_movement(entt::entity camera) const;

    void handle_zoom(entt::entity camera) const;
};


#endif //ALMAQUIES_CAMERA_SYSTEM_HPP
