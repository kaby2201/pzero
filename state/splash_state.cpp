#include "DEFINITIONS.hpp"
#include "splash_state.h"

#include <utility>
#include "main_menu_state.h"

SplashState::SplashState(gameDataRef data) : data(std::move(data)){}

void SplashState::init(){
    // Load and sed the background
    this->data->textures.load(Texture::WELCOME_BACKGROUND_IMG, SPLASH_SCREEN_BACKGROUND);

    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));


    this->data->fonts.load(Font::GAME_TITLE, GAME_TITLE_FONT);
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));

    text.setFillColor(sf::Color::White);
    text.setCharacterSize(90);
    text.setString( GAME_NAME);
    text.setPosition((float)this->data->window.getSize().x/3, (float)this->data->window.getSize().y/2);

    // Load file and play the music
    this->data->music.load(Music::BACKGROUND_MUSIC, MENU_BACKGROUND_MUSIC);
    this->data->sound.setBuffer(this->data->music.get(Music::BACKGROUND_MUSIC));
    this->data->sound.play();
}

void SplashState::handleInput(){
    sf::Event event{};

    while (this->data->window.pollEvent(event)){

        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            this->data->window.close();
        }
    }
}

void SplashState::update(float dt){

    if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
        // TODO - add the to start from here
        this->data->machine.addState(stateRef(new MainMenuState(data)), true);
    }

}

void SplashState::draw(float dt){
    this->data->window.clear();
    this->data->window.draw( this->background);
    this->data->window.draw(text);
    this->data->window.display();
}