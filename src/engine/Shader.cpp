#include "Shader.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

Shader::Shader()
{

}

void Shader::load(const std::string& vFilepath, const std::string& fFilepath)
{
    m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
    m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    loadAndCompile(vFilepath, m_vertexShader);
    errorCheckCompilation(m_vertexShader);

    loadAndCompile(fFilepath, m_fragmentShader);
    errorCheckCompilation(m_fragmentShader);

    m_program = glCreateProgram();
    glAttachShader(m_program, m_vertexShader);
    glAttachShader(m_program, m_fragmentShader);
    glLinkProgram(m_program);

    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
}

int Shader::findUniform(const std::string& name)
{
    return glGetUniformLocation(m_program, name.c_str());
}

void Shader::setUniformMatrix(int location, glm::mat4 data)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(data));
}

void Shader::use()
{
    glUseProgram(m_program);
}

void Shader::loadAndCompile(const std::string& filepath, unsigned int& shader)
{
    std::stringstream sourceStream{};

    std::ifstream file(filepath);
    if(!file)
    {
        throw std::runtime_error("Error: Opening shader file failed.\n");
    }

    sourceStream << file.rdbuf();

    std::string sourceStr{sourceStream.str()};
    const char* source{sourceStr.c_str()};

    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
}

void Shader::errorCheckCompilation(unsigned int& shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Error: Shader compilation failed:\n";
        throw std::runtime_error(infoLog);
    }
}

void Shader::errorCheckLinking(unsigned int& shader)
{
    int success;
    char infoLog[512];

    glGetProgramiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Error: Shader linking failed:\n";
        throw std::runtime_error(infoLog);
    }
}
