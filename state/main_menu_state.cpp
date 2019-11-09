#include "main_menu_state.h"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "splash_state.h"
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>

void MainMenuState::init() {



    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->data->textures.load(Texture::TABLE, TABLE_BACKGROUND);
    table.setTexture(this->data->textures.get(Texture::TABLE));
    table.setScale(0.8, 0.9);
    table.setPosition(SCREEN_WIDTH / 2.f - table.getGlobalBounds().width / 2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height / 2);

// insert images as buttons
    this->data->textures.load(Texture::BUTTON1, PLAY_BUTTON);
    btn1.setTexture(this->data->textures.get(Texture::BUTTON1));
    btn1.setScale(0.3, 0.3);
    btn1.setPosition((table.getPosition().x + table.getGlobalBounds().width - btn1.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 80);

    this->data->textures.load(Texture::BUTTON2, SETTING_BUTTON);
    btn2.setTexture(this->data->textures.get(Texture::BUTTON2));
    btn2.setScale(0.5, 0.5);
    btn2.setPosition((table.getPosition().x + table.getGlobalBounds().width - btn2.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 240);


    this->data->textures.load(Texture::BUTTON3, HELP_BUTTON);
    btn3.setTexture(this->data->textures.get(Texture::BUTTON3));
    btn3.setScale(0.5, 0.5);
    btn3.setPosition((table.getPosition().x + table.getGlobalBounds().width - btn3.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 400);

    // button texts
    this->b1.setString("Play");
    b1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    b1.setCharacterSize(100);
    b1.setFillColor(sf::Color::Black);
    b1.setPosition(table.getPosition().x - b1.getGlobalBounds().width + 350, table.getPosition().y + 80);

    this->b2.setString("Settings");
    b2.setFont(this->data->fonts.get(Font::GAME_TITLE));
    b2.setCharacterSize(100);
    b2.setFillColor(sf::Color::Black);
    b2.setPosition(table.getPosition().x - b2.getGlobalBounds().width + 530, table.getPosition().y + 240);

    this->b3.setString("Help");
    b3.setFont(this->data->fonts.get(Font::GAME_TITLE));
    b3.setCharacterSize(100);
    b3.setFillColor(sf::Color::Black);
    b3.setPosition(table.getPosition().x - b3.getGlobalBounds().width + 350, table.getPosition().y + 400);

    this->data->textures.load(Texture::BUTTON4, EXIT_BUTTON);
    btn4.setTexture(this->data->textures.get(Texture::BUTTON4));
    btn4.setScale(0.25, 0.25);
    btn4.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - btn4.getGlobalBounds().width / 2,
                     table.getPosition().y + 560);

    this->title1.setString("MENU");
    title1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    title1.setCharacterSize(100);
    title1.setFillColor(sf::Color::Black);
    title1.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - title1.getGlobalBounds().width / 2,
                       table.getPosition().y - 100);
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

        if (this->data->input.isSpriteClicked(this->btn4, sf::Mouse::Left, data->window)) {
            data->window.close();
        }

    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
//    data->window.draw(b);
//    data->window.draw(title);
//    data->window.draw(startGameBtn);
//    data->window.setTitle("Game::menu");
    data->window.draw(background);
    data->window.draw(table);
    data->window.draw(btn1);
    data->window.draw(btn2);
    data->window.draw(btn3);
    data->window.draw(btn4);
    data->window.draw(b1);
    data->window.draw(b2);
    data->window.draw(b3);
    data->window.draw(title1);
    data->window.display();
}

void MainMenuState::pause() {
    State::pause();
}

void MainMenuState::resume() {
    State::resume();
}