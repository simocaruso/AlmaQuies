//
// Created by simone on 05/12/25.
//

#ifndef FARMANDCONQUER_SHADER_HPP
#define FARMANDCONQUER_SHADER_HPP
#include <string>
#include <vector>
#include <allegro5/shader.h>


class Shader {
public:
    Shader(const std::string &vertex_path, const std::string &fragment_path);

    ~Shader();

    void use() const;

    void set_float_vec(const std::string &name, const std::vector<float> &values);

private:
    ALLEGRO_SHADER *shader_;
};


#endif //FARMANDCONQUER_SHADER_HPP
