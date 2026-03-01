//
// Created by simone on 07/11/25.
//

#ifndef ALMAQUIES_MOVEMENT_SYSTEM_HPP
#define ALMAQUIES_MOVEMENT_SYSTEM_HPP


#include "system.hpp"
#include "events/move_command_event.hpp"

class MovementSystem : public System {
public:
    MovementSystem(entt::registry* registry, entt::dispatcher &dispatcher);

    void update(int elapsed) override;

    void on_move_command(const MoveCommandEvent &event) const;

private:
    static void apply_deceleration_axis(float &v, float deceleration_strength, int elapsed);
};


#endif //ALMAQUIES_MOVEMENT_SYSTEM_HPP
