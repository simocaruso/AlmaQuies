//
// Created by simone on 04/12/25.
//

#ifndef FARMANDCONQUER_ANIMATION_SYSTEM_HPP
#define FARMANDCONQUER_ANIMATION_SYSTEM_HPP
#include "system.hpp"


class AnimationSystem : public System {
public:
    explicit AnimationSystem(entt::registry* registry);

    void update(int elapsed) override;
};


#endif //FARMANDCONQUER_ANIMATION_SYSTEM_HPP
