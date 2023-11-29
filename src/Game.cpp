#include "Game.hpp"

int main() {
    Game game{};

    return 0;
}

Game::Game() {
    m_texture.load("res/textures/spaceship.png", true);

    m_shader.load("res/shaders/basicV.glsl", "res/shaders/basicF.glsl");
    m_quad.bindToShader(&m_shader);
    m_quad.setColor(glm::vec3{1.0f, 0.0f, 0.1f});
    m_quad.setTexture(&m_texture);

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
