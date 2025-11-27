//
// Created by simone on 20/11/25.
//

#include "atlas_manager.hpp"
#include "../../util/util.hpp"
#include "../systems/rendering/bitmap_target.hpp"
#include "../systems/rendering/renderer.hpp"

AtlasManager::AtlasManager(const int width, const int height) {
    const int old_flags = al_get_new_bitmap_flags();
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    bitmap_ = al_create_bitmap(width, height);
    BitmapTarget target(bitmap_);
    target.begin();
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
    target.end();
    al_set_new_bitmap_flags(old_flags);
    manager_ = sma_atlas_create(width, height);
}

AtlasManager::~AtlasManager() {
    sma_atlas_destroy(manager_);
    al_destroy_bitmap(bitmap_);
}

void AtlasManager::add_sprite(const std::string &name, ALLEGRO_BITMAP* sprite) {
    constexpr float offset = 1.0f;
    smol_atlas_item_t* item = sma_item_add(manager_, al_get_bitmap_width(sprite) + offset * 2, al_get_bitmap_height(sprite) + offset * 2);
    if (item) {
        Vec2 position = {(float) sma_item_x(item) + offset, (float) sma_item_y(item) + offset};
        regions_[name] = AtlasRegion{
            bitmap_, position, al_get_bitmap_width(sprite), al_get_bitmap_height(sprite)
        };
        BitmapTarget target(bitmap_);
        const bool was_bitmap_held = Renderer::get_hold_bimap_status();
        Renderer::set_hold_bitmap(false);
        target.begin();
        Renderer::draw_bitmap(sprite, position, Vec2(0, 0));
        target.end();
        Renderer::set_hold_bitmap(was_bitmap_held);
    } else {
        error(false, "Unable to put image in atlas");
    }
}

AtlasRegion AtlasManager::get_region(const std::string &name) const {
    return regions_.at(name);
}

bool AtlasManager::contains(const std::string &name) const {
    return regions_.contains(name);
}
