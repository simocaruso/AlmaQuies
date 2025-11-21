//
// Created by simone on 03/11/25.
//

#ifndef FARMANDCONQUER_RENDERING_SYSTEM_HPP
#define FARMANDCONQUER_RENDERING_SYSTEM_HPP


#include "map_renderer.hpp"
#include "../system.hpp"
#include "../../display.hpp"
#include "renderer.hpp"
#include "../../map/map.hpp"


class RenderingSystem : public System {
public:
    RenderingSystem(Map* map, entt::registry* registry, Renderer* renderer, Display* display);

    ~RenderingSystem();

    void update(int elapsed) override {
    };

    void render() const;

private:
    Display* display_;
    ALLEGRO_BITMAP* render_buffer;
    Renderer* renderer_;
    MapRenderer map_renderer_;

    void update_camera() const;

    void render_entities() const;
};


#endif //FARMANDCONQUER_RENDERING_SYSTEM_HPP
