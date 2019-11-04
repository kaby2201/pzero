#include "main_menu_state.h"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "setting_state.h"
#include "in_game.h"

void MainMenuState::init() {
    button.setColor(sf::Color::Blue);
    button.setPosition(((float)SCREEN_WIDTH / 2) - (this->button.getGlobalBounds().width / 2),((float)SCREEN_HEIGHT / 2) -(this->button.getGlobalBounds().height / 2));

    this->settings.setString("Settings");
    settings.setFont(this->data->fonts.get(Font::GAME_TITLE));
    settings.setCharacterSize(60);
}

void MainMenuState::handleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            data->window.close();
        }

        if (this->data->input.isTextClicked(this->settings, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new SettingState(data)), true);
            //data->sound.stop();

        }
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
    data->window.draw(b);
    data->window.draw(settings);
    data->window.setTitle("Game::menu");
    data->window.display();
}

void MainMenuState::pause() {
    State::pause();
}

void MainMenuState::resume() {
    State::resume();
}