//
// Created by simone on 28/02/26.
//

#ifndef FARMANDCONQUER_SELECTION_SYSTEM_HPP
#define FARMANDCONQUER_SELECTION_SYSTEM_HPP

#include "system.hpp"
#include "../../../engine/spatial_grid.hpp"

class SelectionSystem : public System {
public:
    SelectionSystem(entt::registry* registry, SpatialGrid* grid);

    void update(int elapsed) override;

private:
    SpatialGrid* grid_;
};


#endif //FARMANDCONQUER_SELECTION_SYSTEM_HPP
