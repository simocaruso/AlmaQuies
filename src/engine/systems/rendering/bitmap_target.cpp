//
// Created by simone on 06/11/25.
//

#include "bitmap_target.hpp"

BitmapTarget::BitmapTarget(ALLEGRO_BITMAP* bitmap): bitmap_(bitmap) {

}

void BitmapTarget::begin() {
    curr_target_ = al_get_target_bitmap();
    al_set_target_bitmap(bitmap_);
}

void BitmapTarget::end() {
    al_set_target_bitmap(curr_target_);
}
