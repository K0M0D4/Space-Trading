#pragma once

#include "engine/Window.hpp"

class Game {
public:
    Game();

private:
    Window m_window{1280, 720, "Space Trading"};

    void mainLoop();
    void update();
    void render();

};
