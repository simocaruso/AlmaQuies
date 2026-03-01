//
// Created by simone on 03/11/25.
//

#ifndef ALMAQUIES_RENDERING_SYSTEM_HPP
#define ALMAQUIES_RENDERING_SYSTEM_HPP


#include "map_renderer.hpp"
#include "outline_renderer.hpp"
#include "../system.hpp"
#include "../../display.hpp"
#include "renderer.hpp"
#include "../../map/map.hpp"
#include "../../../../engine/spatial_grid.hpp"


class RenderingSystem : public System {
public:
    RenderingSystem(Map* map, SpatialGrid* grid, entt::registry* registry, Renderer* renderer, Display* display, FileManager* file_manager);

    void update(int elapsed) override {
    };

    void render() override;

private:
    Display* display_;
    Renderer* renderer_;
    MapRenderer map_renderer_;
    OutlineRenderer occluded_entities_renderer_;
    SpatialGrid *grid_;
    void update_camera() const;

    void render_entities() const;
};


#endif //ALMAQUIES_RENDERING_SYSTEM_HPP
