//
// Created by simone on 06/11/25.
//

#include "rendering_system.hpp"

#include "bitmap_target.hpp"
#include "renderer.hpp"
#include "display_target.hpp"
#include "../../components/camera_component.hpp"
#include "../../../util/util.hpp"
#include "../../components/render_component.hpp"
#include "../../components/transform_component.hpp"

RenderingSystem::RenderingSystem(Map* map, SpatialGrid* grid, entt::registry* registry, Renderer* renderer,
                                 Display* display, FileManager* file_manager)
    : System(registry), grid_(grid), display_(display), renderer_(renderer),
      map_renderer_(map, registry, renderer), occluded_entities_renderer_(registry, renderer, file_manager) {
}

void RenderingSystem::render() {
    update_camera();
    map_renderer_.render();
    render_entities();
    occluded_entities_renderer_.render();
}

void RenderingSystem::update_camera() const {
    const auto camera = *registry_->view<CameraComponent, TransformComponent>().begin();
    Renderer::update_camera(registry_->get<CameraComponent>(camera).transform,
                            registry_->get<TransformComponent>(camera).position,
                            registry_->get<CameraComponent>(camera).zoom);
}

void RenderingSystem::render_entities() const {
    const auto camera_entity = *registry_->view<CameraComponent, TransformComponent>().begin();
    auto &cam = registry_->get<CameraComponent>(camera_entity);
    auto pos = registry_->get<TransformComponent>(camera_entity).position;

    const Vec2 offset{
        BUFF_W / 2.0f,
        BUFF_H / 2.0f
    };
    float radius = compute_rect_radius(BUFF_W / cam.zoom, BUFF_H / cam.zoom);

    auto on_screen_entities = grid_->query_nearby(pos + offset, radius);


    std::vector<entt::entity> sortable_entities = {on_screen_entities.begin(), on_screen_entities.end()};
    std::sort(sortable_entities.begin(), sortable_entities.end(),
              [this](const entt::entity &a, const entt::entity &b) {
                  const auto pos_a = registry_->get<TransformComponent>(a).position;
                  const auto pos_b = registry_->get<TransformComponent>(b).position;
                  if (almost_equal(pos_a.y, pos_b.y))
                      return pos_a.x < pos_b.x;
                  return pos_a.y < pos_b.y;
              });
    Renderer::set_hold_bitmap(true);
    for (auto entity: sortable_entities) {
        auto &transform = registry_->get<TransformComponent>(entity);
        auto &render = registry_->get<RenderComponent>(entity);
        if (is_on_screen(registry_->get<CameraComponent>(camera_entity).transform,
                         transform.position - render.offset,
                         render.width, render.height)) {
            renderer_->draw_resource(render.sprite, transform.position, render.offset);
        }
    }
    Renderer::set_hold_bitmap(false);
}
