//
// Created by simone on 14/03/26.
//

#ifndef ALMAQUIES_AI_CONTROLLER_SYSTEM_HPP
#define ALMAQUIES_AI_CONTROLLER_SYSTEM_HPP

#include "system.hpp"

class AIControllerSystem : public System {
public:
    explicit AIControllerSystem(entt::registry* registry);

    void update(int elapsed) override;
};

#endif //ALMAQUIES_AI_CONTROLLER_SYSTEM_HPP
