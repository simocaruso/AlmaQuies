//
// Created by simone on 26/11/25.
//

#ifndef FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
#define FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
#include "renderer.hpp"
#include "entt/entt.hpp"
#include "../../systems/system.hpp"

class OccludedEntitiesRenderer : public System {
public:
    OccludedEntitiesRenderer(entt::registry* registry, Renderer* renderer);

    void render() override;

private:
    Renderer* renderer_;
};


#endif //FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
