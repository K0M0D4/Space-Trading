#pragma once

#include "engine/Quad.hpp"
#include "engine/Shader.hpp"
#include "engine/Texture.hpp"
#include "engine/Window.hpp"

class Game {
public:
    Game();

private:
    Window m_window{1280, 720, "Space Trading"};

    Shader m_shader;

    Texture m_texture;

    Quad m_quad;

    void mainLoop();
    void update();
    void render();

};
