#include "Quad.hpp"




#include <iostream>




Quad::Quad() {
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verts), m_verts.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_inds), m_inds.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Quad::bindToShader(Shader* shader) {
    m_shader = shader;
}

void Quad::setColor(glm::vec3 color) {
    m_shader->use();
    glUniform4f(m_shader->findUniform("inColor"), color.x, color.y, color.z, 1.0f);
}

void Quad::setColor(glm::vec4 color) {
    m_shader->use();
    glUniform4f(m_shader->findUniform("inColor"), color.x, color.y, color.z, color.w);
}

void Quad::render() {
    m_shader->use();
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
