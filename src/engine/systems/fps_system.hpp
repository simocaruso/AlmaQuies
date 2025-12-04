//
// Created by simone on 04/12/25.
//

#ifndef FARMANDCONQUER_FPS_SYSTEM_HPP
#define FARMANDCONQUER_FPS_SYSTEM_HPP
#include "system.hpp"

struct Fps {
    size_t value = FPS;
    size_t accumulator;
    size_t elapsed;
};

class FpsSystem : public System {
public:
    explicit FpsSystem(entt::registry* registry);

    void update(int elapsed) override;

    void render() override;
};


#endif //FARMANDCONQUER_FPS_SYSTEM_HPP
