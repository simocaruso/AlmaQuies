//
// Created by simone on 28/02/26.
//

#ifndef ALMAQUIES_SELECTION_SYSTEM_HPP
#define ALMAQUIES_SELECTION_SYSTEM_HPP

#include "system.hpp"
#include "../../../engine/spatial_grid.hpp"

class SelectionSystem : public System {
public:
    SelectionSystem(entt::registry* registry, SpatialGrid* grid);

    void update(int elapsed) override;

private:
    SpatialGrid* grid_;

    void clean_entities_states() const;

    void maintain_selection() const;

    void select_entity() const;
};


#endif //ALMAQUIES_SELECTION_SYSTEM_HPP
