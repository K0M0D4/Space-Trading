#include "Game.hpp"

int main() {
    Game game{};

    return 0;
}

Game::Game() {
    m_shader.load("res/shaders/basicV.glsl", "res/shaders/basicF.glsl");
    m_shader.use();

    mainLoop();
}

void Game::mainLoop() {
    while(!m_window.shouldClose()) {
        update();
        render();
    }
}
void Game::update() {

}
void Game::render() {
    m_window.clear(0.1f, 0.1f, 0.2f);

    m_quad.render();

    m_window.swapBuffers();
}
