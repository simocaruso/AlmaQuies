//
// Created by simone on 04/12/25.
//

#ifndef ALMAQUIES_ANIMATION_SYSTEM_HPP
#define ALMAQUIES_ANIMATION_SYSTEM_HPP
#include "system.hpp"


class AnimationSystem : public System {
public:
    explicit AnimationSystem(entt::registry* registry);

    void update(int elapsed) override;
};


#endif //ALMAQUIES_ANIMATION_SYSTEM_HPP
