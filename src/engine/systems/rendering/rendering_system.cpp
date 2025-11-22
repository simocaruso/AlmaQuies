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

RenderingSystem::RenderingSystem(Map* map, entt::registry* registry, Renderer* renderer, Display* display)
    : System(registry), display_(display), renderer_(renderer), map_renderer_(map, registry, renderer) {
    render_buffer = al_create_bitmap(BUFF_W, BUFF_H);
}

RenderingSystem::~RenderingSystem() {
    al_destroy_bitmap(render_buffer);
}

void RenderingSystem::update_camera() const {
    const auto camera = *registry_->view<CameraComponent, TransformComponent>().begin();
    Renderer::update_camera(registry_->get<CameraComponent>(camera).transform,
                            registry_->get<TransformComponent>(camera).position,
                            registry_->get<CameraComponent>(camera).zoom);
}

void RenderingSystem::render() {
    BitmapTarget bitmap_target(render_buffer);
    bitmap_target.begin();
    Renderer::clear_to_color(.5f, .5f, .5f);
    update_camera();
    map_renderer_.render();
    render_entities();
    bitmap_target.end();

    DisplayTarget display_target(display_);
    display_target.begin();
    Renderer::draw_scaled_bitmap(render_buffer, Vec2(0, 0), display_->get_width(), display_->get_height());
    display_target.end();
}

void RenderingSystem::render_entities() const {
    const auto camera = *registry_->view<CameraComponent, TransformComponent>().begin();
    const auto group = registry_->group<RenderComponent>(entt::get<TransformComponent>);
    group.sort<TransformComponent>([](const TransformComponent &a, const TransformComponent &b) {
        if (almost_equal(a.position.y, b.position.y))
            return a.position.x < b.position.x;
        return a.position.y < b.position.y;
    });
    al_hold_bitmap_drawing(true);
    for (const auto entity: group) {
        auto &transform = group.get<TransformComponent>(entity);
        auto &render = group.get<RenderComponent>(entity);
        if (is_on_screen(registry_->get<CameraComponent>(camera).transform,
                         transform.position - render.offset,
                         render.width, render.height)) {
            renderer_->draw_resource(render.sprite_id, transform.position, render.offset);
        }
    }
    al_hold_bitmap_drawing(false);
}
