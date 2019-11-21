#include <SFML/Graphics.hpp>
#include "game_arena.h"
#include "pause_state.h"

void GameArena::init() {
}

void GameArena::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->machine.addState(stateRef(new PauseState(data)), false);
        }
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
        worldMgr.handleEvents(event);
    }
}

void GameArena::update(float dt) {
    worldMgr.update((int)dt);
}

void GameArena::draw(float dt) {
    this->data->window.clear();
    worldMgr.draw(data->window, dt);
    this->data->window.display();
}