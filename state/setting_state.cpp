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
    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->data->textures.load(Texture::TABLE_BACKGROUND, SETTINGS_SCREEN_BACKROUND);
    table.setTexture(this->data->textures.get(Texture::TABLE_BACKGROUND));
    table.setScale(0.7,0.6);
    table.setPosition(SCREEN_WIDTH/2.f -table.getGlobalBounds().width/2,SCREEN_HEIGHT/2.f -table.getGlobalBounds().height/2);

    this->data->textures.load(Texture::OFF_MUTE, MUTE_OFF);
    muteOff.setTexture(this->data->textures.get(Texture::OFF_MUTE));
    muteOff.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-muteOff.getGlobalBounds().width/2,table.getPosition().y+150);

    this->data->textures.load(Texture::ON_MUTE, MUTE_ON);
    muteOn.setTexture(this->data->textures.get(Texture::ON_MUTE));
    muteOn.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-muteOn.getGlobalBounds().width/2,table.getPosition().y+150);

    this->data->textures.load(Texture::VOLUME_INCREASE, VOLUME_ADD);
    Vinrease.setTexture(this->data->textures.get(Texture::VOLUME_INCREASE));
    Vinrease.setPosition(table.getGlobalBounds().width-Vinrease.getGlobalBounds().width+30,
                         (table.getPosition().y+table.getGlobalBounds().height/2-text1.getGlobalBounds().height/2)+60);
    this->data->textures.load(Texture::DECREASE_VOLUME, VOLUME_DECREASE);
    Vdecrease.setTexture(this->data->textures.get(Texture::DECREASE_VOLUME));
    Vdecrease.setPosition((table.getPosition().x+table.getGlobalBounds().width-text1.getGlobalBounds().width-table.getPosition().x/2)-15,
                         (table.getPosition().y+table.getGlobalBounds().height/2-text1.getGlobalBounds().height/2)+60);



    /*text.setString("Test");
    text.setCharacterSize(50);
    text.setFont(data->fonts.get(Font::GAME_TITLE));*/

    //button.setColor(sf::Color::Blue);
    //button.setPosition(((float)SCREEN_WIDTH / 2) - (this->button.getGlobalBounds().width / 2),((float)SCREEN_HEIGHT / 2) -(this->button.getGlobalBounds().height / 2));

    this->text.setString("Mute");
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Black);
    text.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-text.getGlobalBounds().width/2,table.getPosition().y+60);
    this->text1.setString("Sound Volume");
    text1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text1.setCharacterSize(60);
    text1.setFillColor(sf::Color::Black);
    text1.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-text1.getGlobalBounds().width/2,
                      table.getPosition().y+table.getGlobalBounds().height/2-text1.getGlobalBounds().height/2);

    num = data->sound.getVolume();
    this->Vnumber.setString(std::to_string(num));
    Vnumber.setFont(this->data->fonts.get(Font::GAME_TITLE));
    Vnumber.setCharacterSize(60);
    Vnumber.setFillColor(sf::Color::Black);
    Vnumber.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-Vnumber.getGlobalBounds().width/2,
                        (table.getPosition().y+table.getGlobalBounds().height/2-text1.getGlobalBounds().height/2)+40+Vinrease.getGlobalBounds().height/2);

}

void SettingState::resume() {
    State::resume();
}

void SettingState::handleInput() {
    sf::Event event;

    while(this->data->window.pollEvent(event))
    {
        if(this->data->input.isSpriteClicked(this->muteOff, sf::Mouse::Left, data->window))
        {
            if(!alpha)
            {
                this->data->sound.pause();
                alpha = true;
            }
            else if(alpha)
            {
                this->data->sound.play();
                alpha = false;
            }
        }
        if(this->data->input.isSpriteClicked(this->Vinrease, sf::Mouse::Left, data->window))
        {
            if(data->sound.getVolume()+5>=100)
            {
                data->sound.setVolume(100);
            }

            else if(data->sound.getVolume()+5<100) {
                data->sound.setVolume(data->sound.getVolume() + 5);
            }
        }

        if(this->data->input.isSpriteClicked(this->Vdecrease, sf::Mouse::Left, data->window))
        {
            if(data->sound.getVolume()>0 && data->sound.getVolume()<5)
            {
                data->sound.setVolume(0);
            }
            else {
                data->sound.setVolume(data->sound.getVolume() - 5);
            }
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
    if(!alpha)
    {
        this->data->window.draw(this->muteOff);
    }
    if(alpha)
    {
        this->data->window.draw(this->muteOn);
    }
    this->data->window.draw(this->Vinrease);
    this->data->window.draw(this->Vdecrease);
    data->window.draw(text);
    data->window.draw(text1);
    data->window.draw(Vnumber);
    data->window.display();
}

void SettingState::update(float dt) {
    num = this->data->sound.getVolume();
    Vnumber.setString(std::to_string(num));
    Vnumber.setPosition(table.getPosition().x+table.getGlobalBounds().width/2-Vnumber.getGlobalBounds().width/2,
                        (table.getPosition().y+table.getGlobalBounds().height/2-text1.getGlobalBounds().height/2)+40+Vinrease.getGlobalBounds().height/2);
}
