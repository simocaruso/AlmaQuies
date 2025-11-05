//
// Created by simone on 03/11/25.
//

#include "rendering_system.hpp"

RenderingSystem::RenderingSystem(entt::registry* registry, Display* display, ResourceManager* resource_manager)
        : System(registry), display_(display), resource_manager_(resource_manager) {
}

void RenderingSystem::update(int elapsed) {

}
