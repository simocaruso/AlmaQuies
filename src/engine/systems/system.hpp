//
// Created by simone on 31/10/25.
//

#ifndef ALMAQUIES_SYSTEM_HPP
#define ALMAQUIES_SYSTEM_HPP

#include "entt/entt.hpp"

enum SystemType {
    FPS,
    OCCLUSION,
    CAMERA,
    MOVEMENT,
    SPATIAL_GRID,
    SELECTION,
    COLLISION,
    INPUT,
    ANIMATION,
    RENDERING,
    OVERLAY
};

class System {
public:
    explicit System(entt::registry* registry);

    virtual ~System() = default;

    virtual void update(int elapsed) {
    };

    virtual void render() {
    };

protected:
    entt::registry* registry_;
};


#endif //ALMAQUIES_SYSTEM_HPP
