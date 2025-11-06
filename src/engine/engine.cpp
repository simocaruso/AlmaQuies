//
// Created by simone on 31/10/25.
//

#include "engine.hpp"
#include "../util/util.hpp"
#include <allegro5/allegro.h>
#include <memory>

Engine::Engine(const std::string& name) {
    must_init(al_init(), "allegro");
    al_set_app_name(name.c_str());
}

Engine::~Engine() {
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
};

void Engine::init_components() {
    file_manager_ = std::make_unique<FileManager>();
    resource_manager_ = std::make_unique<ResourceManager>(file_manager_.get());
    display_ = std::make_unique<Display>(DISP_W, DISP_H);
    renderer_ = std::make_unique<Renderer>(resource_manager_.get());
    world_ = std::make_unique<World>(display_.get(), renderer_.get(), resource_manager_.get(), file_manager_.get());
    timer_ = al_create_timer(FPS_MILLIS / 1000);
    queue_ = al_create_event_queue();
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_display_event_source(display_->get_display()));
}

void Engine::start() {
    init_components();
    running_ = true;
    start_time_ = (long)(al_get_time() * 1000);
    game_loop();
}

void Engine::process_event(ALLEGRO_EVENT &event) {
    if (display_->is_display_event(event)) {
        display_->process_event(event);
        if (display_->is_closed()) {
            running_ = false;
        }
    } else if (event.type == ALLEGRO_EVENT_TIMER) {
        redraw_ = true;
    }
}

int Engine::update_elapsed() {
    long now = (long) (al_get_time() * 1000);
    int elapsed = now - start_time_;
    start_time_ = now;
    return elapsed;
}

void Engine::game_loop() {
    ALLEGRO_EVENT event;
    int elapsed = 0;
    al_start_timer(timer_);
    while (running_) {
        al_wait_for_event(queue_, &event);
        process_event(event);

        if (redraw_ && al_is_event_queue_empty(queue_)) {
            world_->render();
            redraw_ = false;
        }

        elapsed = update_elapsed();
    }
    al_stop_timer(timer_);
}
