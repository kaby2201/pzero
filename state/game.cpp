#include "game.h"
#include <state/splash_state.h>

Game::Game(int width, int height, const std::string& title) {
    data->window.create(sf::VideoMode(width, height), title);
    data->machine.addState(stateRef(new SplashState(this->data)));
    this->run();
}

void Game::run() {
    float newTime, frameTime, interpolation;
    float currentTime = this->clock.getElapsedTime().asSeconds();

    float accumulator = 0.0f;

    while (this->data->window.isOpen()) {
        this->data->machine.processStateChanges();
        newTime = this->clock.getElapsedTime().asSeconds();

        frameTime = newTime - currentTime;
        if (frameTime > 0.25) {
            frameTime = 2.25;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt) {
            this->data->machine.getActiveState()->handleInput();
            this->data->machine.getActiveState()->update(dt);

            accumulator -= dt;
        }

        interpolation = accumulator /dt;
        this->data->machine.getActiveState()->draw(interpolation);
    }

}
