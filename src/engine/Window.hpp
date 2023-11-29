#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace glob {
    extern int width;
    extern int height;

    void framebufferSizeCallback(GLFWwindow* window, int width, int height);
}

class Window {
public:
    Window();
    Window(int width, int height, const std::string& title);

    ~Window();

    bool shouldClose();

    void clear(float r, float g, float b);
    void swapBuffers();

private:
    GLFWwindow* m_window{};

    void initGLFW();

    void createWindow(int width, int height, const std::string& title);

    void initGLAD();

};
