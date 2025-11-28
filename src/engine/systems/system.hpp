//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_SYSTEM_HPP
#define FARMANDCONQUER_SYSTEM_HPP

#include "entt/entt.hpp"

enum SystemType {
    OCCLUSION,
    MOVEMENT,
    SPATIAL_GRID,
    COLLISION,
    INPUT,
    CAMERA,
    RENDERING,
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


#endif //FARMANDCONQUER_SYSTEM_HPP
