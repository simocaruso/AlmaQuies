//
// Created by simone on 13/11/25.
//

#include "spatial_grid.hpp"
#include <variant>

SpatialGrid::SpatialGrid(const int &cell_size) : cell_size_(cell_size) {
}

void SpatialGrid::clear() {
    cells_.clear();
}

GridRect SpatialGrid::compute_grid_rect(const Vec2 &pos, const int radius) const {
    return GridRect{
        pos.x - radius,
        pos.x + radius,
        pos.y - radius,
        pos.y + radius
    };
}

void SpatialGrid::insert(const entt::entity &entity, const Vec2 &pos, const int radius) {
    auto grid_rect = compute_grid_rect(pos, radius);
    for (int i = grid_rect.min_x; i <= grid_rect.max_x; i += cell_size_) {
        for (int j = grid_rect.min_y; j <= grid_rect.max_y; j += cell_size_) {
            cells_[make_key(Vec2(i, j))].insert(entity);
        }
    }
}

void SpatialGrid::remove(const entt::entity &entity, const Vec2 &pos, const int radius) {
    auto grid_rect = compute_grid_rect(pos, radius);
    for (int i = grid_rect.min_x; i <= grid_rect.max_x; i += cell_size_) {
        for (int j = grid_rect.min_y; j <= grid_rect.max_y; j += cell_size_) {
            cells_[make_key(Vec2(i, j))].erase(entity);
        }
    }
}

long long SpatialGrid::make_key(const Vec2 &pos) const {
    const int cx = pos.x / cell_size_;
    const int cy = pos.y / cell_size_;
    return (static_cast<long long>(cx) << 32) | (cy & 0xffffffff);
}

std::set<entt::entity> SpatialGrid::query_nearby(const Vec2 &pos, const int radius) const {
    return collect_entities(compute_grid_rect(pos, radius));
}

std::set<entt::entity> SpatialGrid::collect_entities(const GridRect grid_rect) const {
    std::set<entt::entity> res;

    for (int i = grid_rect.min_x - cell_size_; i <= grid_rect.max_x; i += cell_size_) {
        for (int j = grid_rect.min_y - cell_size_; j <= grid_rect.max_y; j += cell_size_) {
            auto it = cells_.find(make_key(Vec2(i, j)));
            if (it != cells_.end())
                res.insert(it->second.begin(), it->second.end());
        }
    }

    return res;
}
