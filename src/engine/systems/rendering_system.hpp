//
// Created by simone on 03/11/25.
//

#ifndef FARMANDCONQUER_RENDERING_SYSTEM_HPP
#define FARMANDCONQUER_RENDERING_SYSTEM_HPP


#include "system.hpp"
#include "../display.hpp"
#include "../managers/resource_manager.hpp"

class RenderingSystem : public System {
public:

    RenderingSystem(entt::registry* registry, Display* display, ResourceManager* resource_manager);

    void update(int elapsed) override;

private:
    Display* display_;
    ResourceManager* resource_manager_;
};


#endif //FARMANDCONQUER_RENDERING_SYSTEM_HPP
