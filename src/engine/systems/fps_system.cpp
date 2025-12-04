//
// Created by simone on 04/12/25.
//

#include "fps_system.hpp"

FpsSystem::FpsSystem(entt::registry* registry) : System(registry) {
    registry_->ctx().emplace<Fps>();
}

void FpsSystem::update(int elapsed) {
    auto &fps = registry_->ctx().get<Fps>();
    fps.elapsed += elapsed;
    if (fps.elapsed >= 1000) {
        fps.value = std::round((float) fps.accumulator * 1000.0f / fps.elapsed);
        fps.accumulator = 0;
        fps.elapsed = 0;
    }
}

void FpsSystem::render() {
    auto &fps = registry_->ctx().get<Fps>();
    fps.accumulator++;
}