#include "DEFINITIONS.hpp"
#include "splash_state.h"

#include <utility>
#include "main_menu_state.h"

SplashState::SplashState(gameDataRef data) : data(std::move(data)){}

void SplashState::init(){
    this->data->textures.load(Texture::WELCOME_BACKGROUND_IMG, SPLASH_SCREEN_BACKGROUND);
    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->data->fonts.load(Font::GAME_TITLE, GAME_TITLE_FONT);
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));
    sf::Color color(189, 195, 199,1.0);

    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(90);
    text.setPosition(50.f, 50.f);
    text.setString("Welcome to " GAME_NAME);

    // Load file and play the music
    this->data->music.load(Music::BACKGROUND_MUSIC, MENU_BACKGROUND_MUSIC);
    sound.setBuffer(this->data->music.get(Music::BACKGROUND_MUSIC));
    sound.play();
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
    this->data->window.draw( this->background );
    this->data->window.draw(text);
    this->data->window.display();
}