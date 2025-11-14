//
// Created by simone on 13/11/25.
//

#ifndef FARMANDCONQUER_SPATIAL_GRID_HPP
#define FARMANDCONQUER_SPATIAL_GRID_HPP

#include <unordered_map>
#include "entt/entt.hpp"
#include "../../../util/vec_2.hpp"

class SpatialGrid {
public:
    explicit SpatialGrid(const int &cell_size);

    void clear();

    void insert(const entt::entity &entity, const Vec2 &pos);

    void remove(const entt::entity &entity, const Vec2 &pos);

    std::vector<entt::entity> query_nearby(const Vec2 &pos, const int &radius) const;

    std::vector<entt::entity> query_nearby(const Vec2 &pos, const int &width, const int &height) const;

private:
    int cell_size_;

    std::unordered_map<long long, std::set<entt::entity> > cells_;

    long long make_key(const Vec2 &pos) const;

    std::vector<entt::entity> collect_entities(const int &min_x, const int &min_y, const int &max_x, const int &max_y) const;
};


#endif //FARMANDCONQUER_SPATIAL_GRID_HPP
