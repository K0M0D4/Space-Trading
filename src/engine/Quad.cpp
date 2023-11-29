#include "Quad.hpp"

Quad::Quad() {
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_posVBO);
    glGenBuffers(1, &m_texCoordVBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_posVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verts), m_verts.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_inds), m_inds.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, m_texCoordVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_texCoords), m_texCoords.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
}

void Quad::bindToShader(Shader* shader) {
    m_shader = shader;
}

void Quad::setColor(glm::vec3 color) {
    m_shader->use();
    glUniform1i(m_shader->findUniform("enableTexture"), 0);
    glUniform4f(m_shader->findUniform("inColor"), color.x, color.y, color.z, 1.0f);
}

void Quad::setColor(glm::vec4 color) {
    m_shader->use();
    glUniform1i(m_shader->findUniform("enableTexture"), 0);
    glUniform4f(m_shader->findUniform("inColor"), color.x, color.y, color.z, color.w);
}

void Quad::setTexture(Texture* texture) {
    m_texture = texture;

    m_shader->use();
    if(texture == 0) {
        glUniform1i(m_shader->findUniform("enableTexture"), 0);
    } else {
        glUniform1i(m_shader->findUniform("enableTexture"), 1);
    }
}

void Quad::render() {
    m_shader->use();

    if(m_texture != nullptr)
        glBindTexture(GL_TEXTURE_2D, m_texture->getID());

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
