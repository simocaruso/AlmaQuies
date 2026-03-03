//
// Created by simone on 06/11/25.
//

#include "world.hpp"
#include "managers/input_manager.hpp"
#include "map/map_generator.hpp"
#include "systems/camera_system.hpp"
#include "../util/constants.hpp"
#include "systems/animation_system.hpp"
#include "systems/fps_system.hpp"
#include "systems/input_system.hpp"
#include "systems/movement_system.hpp"
#include "systems/occlusion_system.hpp"
#include "systems/overlay_system.hpp"
#include "systems/player_controller_system.hpp"
#include "systems/selection_system.hpp"
#include "systems/spatial_grid_system.hpp"

World::World(Display* display, Renderer* renderer, ResourceManager* resource_manager, FileManager* file_manager,
             InputManager* input_manager) : display_(display), renderer_(renderer),
                                            resource_manager_(resource_manager), file_manager_(file_manager),
                                            input_manager_(input_manager), display_target_(display) {
    registry_ = std::make_unique<entt::registry>();
    dispatcher_ = std::make_unique<entt::dispatcher>();
    physic_spatial_grid_ = std::make_unique<SpatialGrid>(SPATIAL_GRID_CELL_SIZE);
    rendering_spatial_grid_ = std::make_unique<SpatialGrid>(SPATIAL_GRID_CELL_SIZE);
    auto spatial_sys = add_system<SpatialGridSystem>(SPATIAL_GRID, rendering_spatial_grid_.get(),
                                                     physic_spatial_grid_.get(), registry_.get());
    registry_->on_construct<ColliderComponent>().connect<&SpatialGridSystem::on_created_collidable>(spatial_sys);
    registry_->on_construct<RenderComponent>().connect<&SpatialGridSystem::on_created_renderable>(spatial_sys);
    entity_factory_ = std::make_unique<EntityFactory>(registry_.get(), file_manager_, resource_manager_);
    map_ = std::make_unique<Map>(MapGenerator::generate(128, 32, registry_.get(), entity_factory_.get()));
    entity_factory_->create_from_file("player", Vec2(100, 100));
    entity_factory_->create_camera();
    add_system<MovementSystem>(MOVEMENT, registry_.get(), *dispatcher_);
    add_system<InputSystem>(INPUT, registry_.get(), input_manager_, dispatcher_.get());
    add_system<CollisionSystem>(COLLISION, physic_spatial_grid_.get(), registry_.get());
    add_system<RenderingSystem>(RENDERING, map_.get(), rendering_spatial_grid_.get(), registry_.get(), renderer_,
                                display_, file_manager_);
    add_system<CameraSystem>(CAMERA, registry_.get());
    add_system<SelectionSystem>(SELECTION, registry_.get(), rendering_spatial_grid_.get());
    add_system<OcclusionSystem>(OCCLUSION, registry_.get(), rendering_spatial_grid_.get());
    add_system<PlayerControllerSystem>(PLAYER_CONTROL, registry_.get());
    add_system<OverlaySystem>(OVERLAY, registry_.get(), display);
    add_system<FpsSystem>(FPS, registry_.get());
    add_system<AnimationSystem>(ANIMATION, registry_.get());
}

void World::update(const int elapsed) const {
    dispatcher_->update();
    for (auto &[n, system]: systems_) {
        system->update(elapsed);
    }
}

void World::render() {
    display_target_.begin();
    for (auto &[n, system]: systems_) {
        system->render();
    }
    display_target_.end();
}
