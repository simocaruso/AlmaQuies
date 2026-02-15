//
// Created by simone on 26/11/25.
//

#ifndef FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
#define FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
#include "renderer.hpp"
#include "entt/entt.hpp"
#include "../../systems/system.hpp"
#include "../../shader.hpp"

class OccludedEntitiesRenderer : public System {
public:
    OccludedEntitiesRenderer(entt::registry *registry, Renderer *renderer, FileManager *file_manager);

    void render() override;

private:
    Renderer *renderer_;
    Shader shader_;
};


#endif //FARMANDCONQUER_OCCLUDED_ENTITIES_RENDERER_HPP
