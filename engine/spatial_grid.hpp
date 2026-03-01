//
// Created by simone on 13/11/25.
//

#ifndef ALMAQUIES_SPATIAL_GRID_HPP
#define ALMAQUIES_SPATIAL_GRID_HPP

#include <unordered_map>
#include "entt/entt.hpp"
#include "../src/util/vec_2.hpp"
#include "../src/engine/components/collider_component.hpp"

struct GridRect {
    float min_x, max_x, min_y, max_y;
};

class SpatialGrid {
public:
    explicit SpatialGrid(const int &cell_size);

    void clear();

    void insert(const entt::entity &entity, const Vec2 &pos, int radius);

    void remove(const entt::entity &entity, const Vec2 &pos, int radius);

    std::set<entt::entity> query_nearby(const Vec2 &pos, int radius) const;

private
:
    int cell_size_;

    std::unordered_map<long long, std::set<entt::entity> > cells_;

    GridRect compute_grid_rect(const Vec2 &pos, int radius) const;

    long long make_key(const Vec2 &pos) const;

    std::set<entt::entity> collect_entities(GridRect grid_rect) const;

};


#endif //ALMAQUIES_SPATIAL_GRID_HPP
