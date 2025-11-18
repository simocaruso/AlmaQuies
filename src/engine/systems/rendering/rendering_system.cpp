//
// Created by simone on 06/11/25.
//

#include "rendering_system.hpp"

#include "bitmap_target.hpp"
#include "renderer.hpp"
#include "display_target.hpp"
#include "../../components/camera_component.hpp"
#include "../../components/transform_component.hpp"
#include "../../components/render_component.hpp"

RenderingSystem::RenderingSystem(Map* map, entt::registry* registry, Renderer* renderer, Display* display)
    : System(registry), map_renderer_(map, renderer), display_(display), renderer_(renderer) {
    render_buffer = al_create_bitmap(BUFF_W, BUFF_H);
}

void RenderingSystem::update_camera() const {
    const auto camera = *registry_->view<CameraComponent, TransformComponent>().begin();
    Renderer::update_camera(registry_->get<TransformComponent>(camera).position,
                             registry_->get<CameraComponent>(camera).zoom);
}

void RenderingSystem::render() const {
    const BitmapTarget bitmap_target(render_buffer);
    Renderer::begin(bitmap_target);
    Renderer::clear_to_color(.5f, .5f, .5f);
    update_camera();
    map_renderer_.render();

    const auto group = registry_->group<RenderComponent>(entt::get<TransformComponent>);
    group.sort<TransformComponent>([](const TransformComponent &a, const TransformComponent &b) {
        return a.position.y < b.position.y;
    });

    for (const auto entity: group) {
        auto &transform = group.get<TransformComponent>(entity);
        auto &render = group.get<RenderComponent>(entity);
        renderer_->draw_bitmap(render.sprite_id, transform.position, render.offset);
    }
    Renderer::end(bitmap_target);

    const DisplayTarget display_target(display_);
    Renderer::begin(display_target);
    Renderer::draw_scaled_bitmap(render_buffer, Vec2(0, 0), display_->get_width(), display_->get_height());
    Renderer::end(display_target);
}
