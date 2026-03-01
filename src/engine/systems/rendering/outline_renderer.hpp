//
// Created by simone on 26/11/25.
//

#ifndef ALMAQUIES_OCCLUDED_ENTITIES_RENDERER_HPP
#define ALMAQUIES_OCCLUDED_ENTITIES_RENDERER_HPP
#include "renderer.hpp"
#include "entt/entt.hpp"
#include "../../systems/system.hpp"
#include "../../shader.hpp"

class OutlineRenderer : public System {
public:
    OutlineRenderer(entt::registry *registry, Renderer *renderer, FileManager *file_manager);

    void render() override;

private:
    Renderer *renderer_;
    Shader shader_;
};


#endif //ALMAQUIES_OCCLUDED_ENTITIES_RENDERER_HPP
