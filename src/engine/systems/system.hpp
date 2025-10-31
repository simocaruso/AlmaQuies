//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_SYSTEM_HPP
#define FARMANDCONQUER_SYSTEM_HPP

#include "entt/entt.hpp"

class System {

public:
    explicit System(entt::registry* registry);

    virtual void init() {};

    virtual void update(int elapsed) = 0;

protected:
    entt::registry* registry_;
};


#endif //FARMANDCONQUER_SYSTEM_HPP
