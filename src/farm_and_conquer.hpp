//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_FARM_AND_CONQUER_HPP
#define FARMANDCONQUER_FARM_AND_CONQUER_HPP


#include "engine/engine.hpp"
#include "util/constants.hpp"

class FarmAndConquer {
public:
    void start();
private:
    Engine engine_{GAME_NAME};
};


#endif //FARMANDCONQUER_FARM_AND_CONQUER_HPP
