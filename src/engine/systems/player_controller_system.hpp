//
// Created by simone on 03/03/26.
//

#ifndef FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
#define FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
#include "system.hpp"
#include "../../util/vec_2.hpp"


class PlayerControllerSystem : public System {
public:
    explicit PlayerControllerSystem(entt::registry* registry);

    void update(int elapsed) override;

private:
    void update_movement(entt::entity player) const;

    void move_to(entt::entity player, Vec2 direction) const;
};


#endif //FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
