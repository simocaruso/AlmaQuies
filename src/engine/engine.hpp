//
// Created by simone on 31/10/25.
//

#ifndef FARMANDCONQUER_ENGINE_HPP
#define FARMANDCONQUER_ENGINE_HPP


#include <string>
#include <allegro5/allegro.h>
#include <memory>
#include "display.hpp"

class Engine {
public:
    explicit Engine(const std::string &name);

    ~Engine();

    void start();

private:
    std::unique_ptr<Display> display_;
    ALLEGRO_TIMER* timer_{};
    ALLEGRO_EVENT_QUEUE* queue_{};
    long start_time_ = 0;
    bool redraw_ = false;
    bool running_ = false;

    void process_event(ALLEGRO_EVENT &event);

    int update_elapsed();

    void game_loop();
};


#endif //FARMANDCONQUER_ENGINE_HPP
