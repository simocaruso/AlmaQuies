//
// Created by simone on 06/11/25.
//

#include "display_target.hpp"

DisplayTarget::DisplayTarget(Display* display): display_(display) {
}

void DisplayTarget::begin() const {
    al_set_target_backbuffer(display_->get_display());
}

void DisplayTarget::end() const {
    al_flip_display();
}
