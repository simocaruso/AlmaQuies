//
// Created by simone on 03/11/25.
//

#ifndef FARMANDCONQUER_RENDERING_SYSTEM_HPP
#define FARMANDCONQUER_RENDERING_SYSTEM_HPP


#include "../system.hpp"
#include "../../display.hpp"
#include "../../managers/resource_manager.hpp"
#include "renderer.hpp"
#include "bitmap_target.hpp"

class RenderingSystem : public System {
public:
    RenderingSystem(entt::registry* registry, Renderer* renderer, Display* display);

    void update(int elapsed) override {
    };

    void render() const;

private:
    Display* display_;
    ALLEGRO_BITMAP* render_buffer;
    Renderer* renderer_;

    void update_camera() const;
};


#endif //FARMANDCONQUER_RENDERING_SYSTEM_HPP
