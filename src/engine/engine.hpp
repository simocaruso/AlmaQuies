//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_ENGINE_HPP
#define FARMANDCONQUER_ENGINE_HPP


#include <string>
#include <allegro5/allegro.h>

class Engine {
public:
    explicit Engine(const std::string& name);

    ~Engine();

    void start();

private:
    ALLEGRO_TIMER* timer{};
    ALLEGRO_EVENT_QUEUE* queue{};
    long start_time = 0;

    void game_loop();

    int update_elapsed();
};


#endif //FARMANDCONQUER_ENGINE_HPP
