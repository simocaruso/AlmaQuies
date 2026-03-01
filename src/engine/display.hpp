//
// Created by simone on 31/10/25.
//

#ifndef ALMAQUIES_DISPLAY_HPP
#define ALMAQUIES_DISPLAY_HPP

#include <allegro5/allegro.h>

class Display {
public:
    Display(int disp_w, int disp_h);

    ~Display();

    int get_width() const;

    int get_height() const;

    ALLEGRO_DISPLAY* get_display() const { return display_; }

    bool is_closed() const { return closed_; }

    static bool is_display_event(const ALLEGRO_EVENT &ev);

    void process_event(const ALLEGRO_EVENT &ev);

    void toggle_fullscreen() const;
private:
    ALLEGRO_DISPLAY* display_;

    bool closed_ = false;
};


#endif //ALMAQUIES_DISPLAY_HPP
