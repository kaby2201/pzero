#include <iostream>
#include "pause_state.h"
#include "DEFINITIONS.hpp"

PauseState::PauseState(gameDataRef data) : data(std::move(data)) {
}

void PauseState::init() {
    data->window.setTitle("PAUSE STATE");
    background.setTexture(data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    data->textures.load(Texture::MENU_BOARD_BACKGROUND, MENU_BACKGROUND_BOARD);
    data->textures.load(Texture::PAUSE_HEADER, PAUSE_HEADER_MENU);

    backgroundBoard.setTexture(data->textures.get(Texture::MENU_BOARD_BACKGROUND));
    pauseHeader.setTexture(data->textures.get(Texture::PAUSE_HEADER));
    backgroundBoard.setPosition((float)data->window.getSize().x / 5, (float)data->window.getSize().y / 5);
}

void PauseState::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            data->window.close();
        }
        // When resume button is clicked
        if (this->data->input.isSpriteClicked(pauseHeader, sf::Mouse::Left, data->window)) {
            this->data->machine.removeState();
        }
    }
}

void PauseState::update(float dt) {
    std::cout << dt << std::endl;
}

void PauseState::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.draw(backgroundBoard);
    data->window.draw(pauseHeader);
    data->window.display();
}

void PauseState::pause() {
    State::pause();
}

void PauseState::resume() {
    State::resume();
}
