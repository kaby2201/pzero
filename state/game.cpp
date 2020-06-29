#include "game.h"
#include "splash_state.h"

Game::Game(int width, int height, const std::string& title) {

    // Set window to fullscreen
    #if (defined (LINUX) || defined (__linux__))
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
    #elif (defined (_WIN32) || defined (_WIN64))
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
    #elif defined(__APPLE__) && defined(__MACH__)
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Resize);
    #else data->window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
    #endif

    // will limit the number of frames displayed to the refresh rate of the monitor. This can avoid some visual artifacts,
    // and limit the framerate to a good value (but not constant across different computers).
    //Vertical synchronization is disabled by default.
    data->window.setVerticalSyncEnabled(true);

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
