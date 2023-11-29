#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <array>

class Quad {
public:
    Quad();

    void render();

private:
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
