//
// Created by simone on 06/11/25.
//

#include "bitmap_target.hpp"

BitmapTarget::BitmapTarget(ALLEGRO_BITMAP* bitmap): bitmap_(bitmap) {

}

void BitmapTarget::begin() const {
    al_set_target_bitmap(bitmap_);
}
