//
// Created by simone on 07/11/25.
//

#ifndef ALMAQUIES_MOVEMENT_SYSTEM_HPP
#define ALMAQUIES_MOVEMENT_SYSTEM_HPP


#include "system.hpp"

class MovementSystem : public System {
public:
    MovementSystem(entt::registry* registry);

    void update(int elapsed) override;

private:
    static void apply_deceleration_axis(float &v, float deceleration_strength, int elapsed);
};


#endif //ALMAQUIES_MOVEMENT_SYSTEM_HPP
