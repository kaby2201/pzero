#include "main_menu_state.h"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "splash_state.h"
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
void MainMenuState::init() {

    button.setColor(sf::Color::Blue);
    button.setPosition(((float)SCREEN_WIDTH / 2) - (this->button.getGlobalBounds().width / 2),((float)SCREEN_HEIGHT / 2) -(this->button.getGlobalBounds().height / 2));

    this->title.setString("Angry Mario");
    title.setFont(this->data->fonts.get(Font::GAME_TITLE));
    title.setFillColor(sf::Color::Green);
    title.setCharacterSize(60);

    // lager start game knapp
    startGameBtn.setFont(this->data->fonts.get(Font::GAME_TITLE));
    startGameBtn.setCharacterSize(50.f);
    startGameBtn.setPosition((float)data->window.getSize().x/2-30, (float)data->window.getSize().y/2);
    startGameBtn.setFillColor(sf::Color::Green);
    startGameBtn.setString("Playing");


}

void MainMenuState::handleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            data->window.close();
        }

        if (this->data->input.isTextClicked(this->title, sf::Mouse::Left, data->window)) {
            std::cout << "Go to the game screen; \n";
            data->sound.stop();
        }
        if(this->data->input.isTextClicked(this->startGameBtn,sf::Mouse::Left,data->window)){
            this->data->machine.addState(stateRef(new SplashState(data)), true);
        }
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
    data->window.draw(b);
    data->window.draw(title);
    data->window.draw(startGameBtn);
    data->window.setTitle("Game::menu");
    data->window.display();
}

void MainMenuState::pause() {
    State::pause();
}

void MainMenuState::resume() {
    State::resume();
}