//
// Created by simone on 31/10/25.
//

#include "display.hpp"
#include "../util/util.hpp"

Display::Display(const int disp_w, const int disp_h) {
    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE | ALLEGRO_PROGRAMMABLE_PIPELINE);
    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    display_ = al_create_display(disp_w, disp_h);
    must_init(display_, "display");
}

Display::~Display() {
    if (display_)
        al_destroy_display(display_);
}

int Display::get_width() const {
    return al_get_display_width(display_);
}

int Display::get_height() const {
    return al_get_display_height(display_);
}

void Display::toggle_fullscreen() const {
    al_set_display_flag(display_, ALLEGRO_FULLSCREEN_WINDOW,
                        !(al_get_display_flags(display_) & ALLEGRO_FULLSCREEN_WINDOW));
}

bool Display::is_display_event(const ALLEGRO_EVENT &ev) {
    return ev.type >= ALLEGRO_EVENT_DISPLAY_EXPOSE &&
           ev.type <= ALLEGRO_EVENT_DISPLAY_HALT_DRAWING;
}


void Display::process_event(const ALLEGRO_EVENT &ev) {
    switch (ev.type) {
        case ALLEGRO_EVENT_DISPLAY_RESIZE:
            al_acknowledge_resize(display_);
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            closed_ = true;
            break;
    }
}