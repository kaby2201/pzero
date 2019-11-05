#include "setting_state.h"
#include "DEFINITIONS.hpp"
#include "setting_state.h"
#include "main_menu_state.h"
#include <iostream>
#include "game.h"

void SettingState::pause() {
    State::pause();
}

void SettingState::init() {
    this->data->textures.load(Texture::WELCOME_BACKGROUND_IMG, SPLASH_SCREEN_BACKGROUND);
    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));
    this->data->textures.load(Texture::TABLE_BACKGROUND, SETTINGS_SCREEN_BACKROUND);
    table.setTexture(this->data->textures.get(Texture::TABLE_BACKGROUND));
    table.setScale(0.7,0.6);
    table.setPosition(SCREEN_WIDTH/2.f -table.getGlobalBounds().width/2,SCREEN_HEIGHT/2.f -table.getGlobalBounds().height/2);
    this->data->textures.load(Texture::OFF_BACKGROUND,MUTE_OFF);
    muteOff.setTexture(this->data->textures.get(Texture::TABLE_BACKGROUND));


    /*text.setString("Test");
    text.setCharacterSize(50);
    text.setFont(data->fonts.get(Font::GAME_TITLE));*/

    //button.setColor(sf::Color::Blue);
    //button.setPosition(((float)SCREEN_WIDTH / 2) - (this->button.getGlobalBounds().width / 2),((float)SCREEN_HEIGHT / 2) -(this->button.getGlobalBounds().height / 2));

    this->text.setString("Mute/Play");
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Black);
    this->text1.setString("Sound Volume");
    text1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text1.setCharacterSize(60);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(0,70);
    /*this->text2.setString("Decrease Volume");
    text2.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text2.setCharacterSize(60);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(0,130);*/
    //this->buttons.push_back(button);
}

void SettingState::resume() {
    State::resume();
}

void SettingState::handleInput() {
    sf::Event event;

    while(this->data->window.pollEvent(event))
    {
        if(this->data->input.isTextClicked(this->text, sf::Mouse::Left, data->window))
        {
            if(!alpha)
            {
                this->data->sound.pause();
                alpha = true;
                std::cout<<"x: "<<table.getGlobalBounds().width<<std::endl;
                std::cout<<"y: "<<table.getGlobalBounds().height<<std::endl;
            }
            else if(alpha)
            {
                this->data->sound.play();
                alpha = false;
            }
        }
        if(this->data->input.isTextClicked(this->text1, sf::Mouse::Left, data->window))
        {
            data->sound.setVolume(data->sound.getVolume()+5);
        }
        if(this->data->input.isTextClicked(this->text2, sf::Mouse::Left, data->window))
        {
            data->sound.setVolume(data->sound.getVolume()-5);
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        {
            this->data->machine.addState(stateRef(new MainMenuState(data)), true);
        }
    }

}

void SettingState::draw(float dt) {
    data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(this->table);
    this->data->window.draw(this->muteOff);
    data->window.draw(text);
    data->window.draw(text1);
    data->window.draw(text2);
    data->window.display();
}

void SettingState::update(float dt) {

}
