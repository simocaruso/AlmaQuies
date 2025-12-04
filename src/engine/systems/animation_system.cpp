//
// Created by simone on 04/12/25.
//

#include "animation_system.hpp"

#include "../components/animation_component.hpp"
#include "../components/name_component.hpp"
#include "../components/render_component.hpp"
#include "../components/state_component.hpp"
#include "fmt/format.h"

AnimationSystem::AnimationSystem(entt::registry* registry) : System(registry) {
}

void AnimationSystem::update(int elapsed) {
    auto view = registry_->view<AnimationComponent>();

    for (auto entity: view) {
        auto &animation = view.get<AnimationComponent>(entity);
        auto &sprite = registry_->get<RenderComponent>(entity).sprite;
        if (!registry_->get<StateComponent>(entity).is_moving) {
            sprite = fmt::format(
                "{}", registry_->get<NameComponent>(entity).name);
            continue;
        }

        animation.curr_elapsed += elapsed;
        if (animation.curr_elapsed > animation.active.frame_speed) {
            animation.curr_frame += 1;
            animation.curr_frame %= animation.active.num_frames;
            sprite = fmt::format(
                "{}_{}{}", registry_->get<NameComponent>(entity).name, animation.active.name, animation.curr_frame + 1);
            animation.curr_elapsed = 0;
        }
    }
}
