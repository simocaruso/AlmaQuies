//
// Created by simone on 31/10/25.
//

#ifndef ALMAQUIES_HPP
#define ALMAQUIES_HPP


#include "engine/engine.hpp"
#include "util/constants.hpp"

class AlmaQuies {
public:
    void start();
private:
    Engine engine_{GAME_NAME};
};


#endif //ALMAQUIES_HPP
