#include "main_menu_state.h"
#include <iostream>
#include "DEFINITIONS.hpp"

void MainMenuState::init() {
    button.setColor(sf::Color::Blue);
    button.setPosition(((float)SCREEN_WIDTH / 2) - (this->button.getGlobalBounds().width / 2),((float)SCREEN_HEIGHT / 2) -(this->button.getGlobalBounds().height / 2));

    this->title.setString("Click here to start the game");
    title.setFont(this->data->fonts.get(Font::GAME_TITLE));
    title.setCharacterSize(55);
}

void MainMenuState::handleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            data->window.close();
        }

        if (this->data->input.isTextClicked(this->title, sf::Mouse::Left, data->window)) {
            std::cout << "Go to the game screen; \n";
            data->sound.stop();
        }
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
    data->window.draw(b);
    data->window.draw(title);
    data->window.setTitle("Game::menu");
    data->window.display();
}

void MainMenuState::pause() {
    State::pause();
}

void MainMenuState::resume() {
    State::resume();
}