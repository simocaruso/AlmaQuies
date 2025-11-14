//
// Created by simone on 13/11/25.
//

#include "spatial_grid.hpp"

SpatialGrid::SpatialGrid(const int &cell_size) : cell_size_(cell_size) {
}

void SpatialGrid::clear() {
    cells_.clear();
}

void SpatialGrid::insert(const entt::entity &entity, const Vec2 &pos) {
    cells_[make_key(pos)].insert(entity);
}

void SpatialGrid::remove(const entt::entity &entity, const Vec2 &pos) {
    cells_[make_key(pos)].erase(entity);
}

long long SpatialGrid::make_key(const Vec2 &pos) const {
    const int cx = pos.x / cell_size_;
    const int cy = pos.y / cell_size_;
    return (static_cast<long long>(cx) << 32) | (cy & 0xffffffff);
}

std::vector<entt::entity> SpatialGrid::query_nearby(const Vec2 &pos, const int &radius) const {
    std::vector<entt::entity> res;
    const int min_x = pos.x - radius;
    const int min_y = pos.y - radius;
    const int max_x = pos.x + radius;
    const int max_y = pos.y + radius;

    return collect_entities(min_x, min_y, max_x, max_y);
}

std::vector<entt::entity> SpatialGrid::collect_entities(const int &min_x, const int &min_y,
                                                        const int &max_x, const int &max_y) const {
    std::vector<entt::entity> res;

    for (int i = min_x; i <= max_x; i++) {
        for (int j = min_y; j <= max_y; j++) {
            auto it = cells_.find(make_key(Vec2(i, j)));
            if (it != cells_.end()) {
                // insert all entities from the set into the vector
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
        }
    }

    return res;
}
