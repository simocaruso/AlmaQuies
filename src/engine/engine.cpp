//
// Created by simone on 31/10/25.
//

#include "engine.hpp"
#include "../util/util.hpp"
#include "../util/constants.hpp"
#include <allegro5/allegro.h>

Engine::Engine(const std::string& name) {
    must_init(al_init(), "allegro");
    al_set_app_name(name.c_str());
}

Engine::~Engine() {
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
};

void Engine::start() {
    timer = al_create_timer(FPS_MILLIS/1000);
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_timer_event_source(timer));
    game_loop();
}

void Engine::game_loop() {
    ALLEGRO_EVENT event;
    bool redraw = false;
    int elapsed = 0;
    al_start_timer(timer);
    for (;;) {
        al_wait_for_event(queue, &event);
        elapsed = update_elapsed();
    }
    al_stop_timer(timer);
}

int Engine::update_elapsed() {
    long now = (long) (al_get_time() * 1000);
    int elapsed = now - start_time;
    start_time = now;
    return elapsed;
}
