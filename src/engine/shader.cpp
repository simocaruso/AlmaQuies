//
// Created by simone on 05/12/25.
//

#include "shader.hpp"
#include "../util/util.hpp"
#include "fmt/format.h"
#include "systems/rendering/renderer.hpp"

Shader::Shader(const std::string &vertex_path, const std::string &fragment_path) {
    shader_ = al_create_shader(ALLEGRO_SHADER_AUTO);
    if (!vertex_path.empty() && !al_attach_shader_source_file(shader_, ALLEGRO_VERTEX_SHADER, vertex_path.c_str())) {
        error(false, fmt::format("Failed to load vertex shader {}", al_get_shader_log(shader_)).c_str());
    }
    if (!fragment_path.empty() && !al_attach_shader_source_file(shader_, ALLEGRO_PIXEL_SHADER, fragment_path.c_str())) {
        error(false, fmt::format("Failed to load fragment shader {}", al_get_shader_log(shader_)).c_str());
    }
    if (!al_build_shader(shader_)) {
        error(false, fmt::format("Shader Error: {}", al_get_shader_log(shader_)).c_str());
    }
}

Shader::~Shader() {
    al_destroy_shader(shader_);
}

void Shader::use() const {
    Renderer::use(shader_);
}

void Shader::set_float_vec(const std::string &name, const std::vector<float> &values) {
    al_set_shader_float_vector(name.c_str(), values.size(), values.data(), 1);
}
