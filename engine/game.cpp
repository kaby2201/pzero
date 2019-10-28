#include <memory>
#include <iostream>

#include <SFML/Window.hpp>

#include "game.h"
#include "machine.h"

bool Game::init() {

    // Initializer all the resources
    if(!Config::loadResources()){
        return false;
    }

    // Standard SFML setup
    window.create(sf::VideoMode(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT), GAME_NAME);

    // Double the size of the screen
    sf::View view = window.getDefaultView();
    view.setSize(view.getSize().x / 2, view.getSize().y / 2);
    view.setCenter(view.getCenter().x / 2, view.getCenter().y / 2);
    window.setView(view);

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    return true;
}

void Game::run() {
    Machine machine;

    while (machine.isRunning()) {
        sf::Event event{};
        while (this->window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    machine.setState(Machine::StateId::STATE_EXIT);
                    break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                machine.setState(Machine::StateId::STATE_EXIT);
            }
        }
        machine.goNext();
        this->window.clear(sf::Color::Black);
        this->window.display();
    }
}