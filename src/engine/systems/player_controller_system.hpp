//
// Created by simone on 03/03/26.
//

#ifndef FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
#define FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
#include "system.hpp"


class PlayerControllerSystem : public System {
public:
    explicit PlayerControllerSystem(entt::registry* registry);

    void update(int elapsed) override;

private:
    void handle_input(entt::entity player) const;
};


#endif //FARMANDCONQUER_PLAYER_CONTROLLER_SYSTEM_HPP
