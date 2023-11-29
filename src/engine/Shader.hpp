#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

class Shader
{
public:
    Shader();

    void load(const std::string& vFilepath, const std::string& fFilepath);

    int findUniform(const std::string& name);
    void setUniformMatrix(int location, glm::mat4 data);

    void use();

private:
    unsigned int m_vertexShader{};
    unsigned int m_fragmentShader{};

    unsigned int m_program{};

    void loadAndCompile(const std::string& filepath, unsigned int& shader);
    void errorCheckCompilation(unsigned int& shader);
    void errorCheckLinking(unsigned int& shader);

};
