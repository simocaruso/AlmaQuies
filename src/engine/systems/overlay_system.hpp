//
// Created by simone on 03/12/25.
//

#ifndef FARMANDCONQUER_OVERLAY_SYSTEM_HPP
#define FARMANDCONQUER_OVERLAY_SYSTEM_HPP
#include "system.hpp"
#include "../display.hpp"
#include "../overlay/window.hpp"

class OverlaySystem : public System {
public:
    OverlaySystem(entt::registry* registry, const Display* display);

    void update(int elapsed) override;

    void render() override;
private:
    std::vector<Window> windows_;
};


#endif //FARMANDCONQUER_OVERLAY_SYSTEM_HPP
