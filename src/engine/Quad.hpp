#pragma once

#include "Shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <array>

class Quad {
public:
    Quad();

    void bindToShader(Shader* shader);

    void setColor(glm::vec3 color);
    void setColor(glm::vec4 color);

    void render();

private:
    Shader* m_shader;

    unsigned int m_VAO{};
    unsigned int m_VBO{};
    unsigned int m_EBO{};

    std::array<float, 12> m_verts {
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
    };

    std::array<unsigned int, 6> m_inds {
        0, 1, 2,
        1, 3, 2
    };

};
