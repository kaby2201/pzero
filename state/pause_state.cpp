#include <iostream>
#include "pause_state.h"
#include "DEFINITIONS.hpp"

PauseState::PauseState(gameDataRef data) : data(std::move(data)) {}

void PauseState::init() {
    data->window.setView(data->window.getDefaultView());
    data->textures.load(Texture::PAUSE_HEADER, PAUSE_IMAGE);
    pauseButton.setTexture(data->textures.get(Texture::PAUSE_HEADER));
    pauseButton.setPosition((data->window.getSize().x - pauseButton.getTexture()->getSize().x)/2,
                            (data->window.getSize().y - pauseButton.getTexture()->getSize().y)/2);
}

void PauseState::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->machine.removeState(); // remove from stack will resume
        }
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }

        // When resume button is clicked
        if (this->data->input.isSpriteClicked(pauseButton, sf::Mouse::Left, data->window)) {
            this->data->machine.removeState();
        }
    }
}

void PauseState::update(float dt) {
}

void PauseState::draw(float dt) {
    data->window.draw(pauseButton);
    data->window.display();
}

void PauseState::pause() {
    State::pause();
}

void PauseState::resume() {
    State::resume();
}
