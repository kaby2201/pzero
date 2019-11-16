#include "main_menu_state.h"
#include <iostream>
#include "DEFINITIONS.hpp"

#include "setting_state.h"
#include "SFML/Graphics.hpp"
#include "game_arena.h"
#include "state_help.h"

void MainMenuState::init() {

    this->settings.setString("Settings");
    settings.setFont(this->data->fonts.get(Font::GAME_TITLE));
    settings.setCharacterSize(60);

    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->data->textures.load(Texture::TABLE, TABLE_BACKGROUND);
    table.setTexture(this->data->textures.get(Texture::TABLE));
    table.setScale(0.9, 1.0);
    table.setPosition(SCREEN_WIDTH / 2.f - table.getGlobalBounds().width / 2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height / 2);

    // insert images and texts of menu state
    this->data->textures.load(Texture::BUTTON_PLAY, PLAY_BUTTON);
    btnPlay.setTexture(this->data->textures.get(Texture::BUTTON_PLAY));
    btnPlay.setScale(0.25, 0.25);
    btnPlay.setPosition((table.getPosition().x + table.getGlobalBounds().width - btnPlay.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 80);

    this->data->textures.load(Texture::BUTTON_SETTING, SETTING_BUTTON);
    btnSetting.setTexture(this->data->textures.get(Texture::BUTTON_SETTING));
    btnSetting.setScale(0.4, 0.4);
    btnSetting.setPosition((table.getPosition().x + table.getGlobalBounds().width - btnSetting.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 240);


    this->data->textures.load(Texture::BUTTON_HELP, HELP_BUTTON);
    btnHelp.setTexture(this->data->textures.get(Texture::BUTTON_HELP));
    btnHelp.setScale(0.4, 0.4);
    btnHelp.setPosition((table.getPosition().x + table.getGlobalBounds().width - btnHelp.getGlobalBounds().width -
                      table.getPosition().x / 2) + 80, table.getPosition().y + 400);

    this->data->textures.load(Texture::BUTTON_SCORE, SCORE_BUTTON);
    btnScore.setTexture(this->data->textures.get(Texture::BUTTON_SCORE));
    btnScore.setScale(0.4, 0.4);
    btnScore.setPosition((table.getPosition().x + table.getGlobalBounds().width - btnScore.getGlobalBounds().width -
                         table.getPosition().x / 2) + 80, table.getPosition().y + 560);
    // buttons text for Menu

    this->btn_play.setString("Play");
    btn_play.setFont(this->data->fonts.get(Font::GAME_TITLE));
    btn_play.setCharacterSize(80);
    btn_play.setFillColor(sf::Color::Black);
    btn_play.setPosition(table.getPosition().x - btn_play.getGlobalBounds().width + 350, table.getPosition().y + 80);

    // setting button
    this->btn_setting.setString("Setting");
    btn_setting.setFont(this->data->fonts.get(Font::GAME_TITLE));
    btn_setting.setCharacterSize(80);
    btn_setting.setFillColor(sf::Color::Black);
    btn_setting.setPosition(table.getPosition().x - btn_setting.getGlobalBounds().width + 470, table.getPosition().y + 240);

    // help button
    this->btn_help.setString("Help");
    btn_help.setFont(this->data->fonts.get(Font::GAME_TITLE));
    btn_help.setCharacterSize(80);
    btn_help.setFillColor(sf::Color::Black);
    btn_help.setPosition(table.getPosition().x - btn_help.getGlobalBounds().width + 350, table.getPosition().y + 400);

    // score button
    this->btn_score.setString("Score");
    btn_score.setFont(this->data->fonts.get(Font::GAME_TITLE));
    btn_score.setCharacterSize(80);
    btn_score.setFillColor(sf::Color::Black);
    btn_score.setPosition(table.getPosition().x - btn_score.getGlobalBounds().width + 400, table.getPosition().y + 560);

    // exit button
    this->data->textures.load(Texture::BUTTON_EXIT, EXIT_MENU_BUTTON);
    btnExit.setTexture(this->data->textures.get(Texture::BUTTON_EXIT));
    btnExit.setScale(0.4, 0.4);
    btnExit.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - btnExit.getGlobalBounds().width / 2, table.getPosition().y + 700);

    // Menu text that is on the top of the Menu
    this->titleMenu.setString("MENU");
    titleMenu.setFont(this->data->fonts.get(Font::GAME_TITLE));
    titleMenu.setCharacterSize(100);
    titleMenu.setFillColor(sf::Color::Black);
    titleMenu.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - titleMenu.getGlobalBounds().width / 2,
                       table.getPosition().y - 100);

}

void MainMenuState::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            data->window.close();
        }


        if (this->data->input.isSpriteClicked(this->btnPlay, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new GameArena(data)), true);

        }

        if (this->data->input.isSpriteClicked(this->btnSetting, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new SettingsState(data)), true);
        }

        if (this->data->input.isSpriteClicked(this->btnHelp, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new state_help(data)), true);
        }

        if (this->data->input.isSpriteClicked(this->btnExit, sf::Mouse::Left, data->window)) {
            data->window.close();
        }

    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(float dt) {
    data->window.clear();
    data->window.draw(b);
    data->window.draw(settings);

    data->window.draw(background);
    data->window.draw(titleMenu);
    data->window.draw(table);
    data->window.draw(btnPlay);
    data->window.draw(btnSetting);
    data->window.draw(btnHelp);
    data->window.draw(btnScore);
    data->window.draw(btnExit);
    data->window.draw(btn_play);
    data->window.draw(btn_setting);
    data->window.draw(btn_help);
    data->window.draw(btn_score);
    data->window.display();
}

void MainMenuState::pause() {
    State::pause();
}

void MainMenuState::resume() {
    State::resume();
}