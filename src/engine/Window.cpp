#include "Window.hpp"

#include <iostream>

namespace glob {
    int width{};
    int height{};

    void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
        glob::width = width;
        glob::height = height;
    }
}

Window::Window() {
    
}

Window::Window(int width, int height, const std::string& title) {
    initGLFW();
    glob::width = width;
    glob::height = height;
    createWindow(width, height, title);
    initGLAD();

    glViewport(0, 0, glob::width, glob::height);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(m_window);
}

void Window::clear(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::initGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::createWindow(int width, int height, const std::string& title) {
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if(m_window == nullptr) {
        std::cout << "Error: Window creation failed: " << title << '\n';
        glfwTerminate();
    } else {
        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, glob::framebufferSizeCallback);
    }
}   

void Window::initGLAD() {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error: GLAD initialization failed\n";
    }
}
