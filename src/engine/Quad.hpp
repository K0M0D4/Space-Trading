#pragma once

#include "Shader.hpp"
#include "Texture.hpp"

#include <glad/glad.h>
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
    void setTexture(Texture* texture);

    void render();

private:
    Shader* m_shader{};
    Texture* m_texture{};

    unsigned int m_VAO{};
    unsigned int m_posVBO{};
    unsigned int m_texCoordVBO{};
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

    std::array<float, 8> m_texCoords {
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f
    };

};
