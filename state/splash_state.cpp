#include "DEFINITIONS.hpp"
#include "splash_state.h"

#include <utility>
#include "main_menu_state.h"

SplashState::SplashState(gameDataRef data) : data(std::move(data)) {}

void SplashState::init() {

    this->data->window.setFramerateLimit(30);
    // Load and sed the background
    this->data->textures.load(Texture::WELCOME_BACKGROUND_IMG, SPLASH_SCREEN_BACKGROUND);
    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->data->fonts.load(Font::GAME_TITLE, GAME_TITLE_FONT);
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));

    text.setFillColor(sf::Color(71, 71, 135));
    text.setCharacterSize(190);

    text.setString( GAME_NAME " 2019");

    text.setPosition((float) data->window.getSize().x / 4, (float) data->window.getSize().y / 3);

    // Load file and play the music
    this->data->music.load(Music::BACKGROUND_MUSIC, MENU_BACKGROUND_MUSIC);
    this->data->sound.setBuffer(this->data->music.get(Music::BACKGROUND_MUSIC));
    this->data->sound.setVolume(30);
    this->data->sound.play();

    this->data->textures.load(Texture::BACKGROUND_CLOUD_TEXTURE, BACKGROUND_CLOUD);
    cloud.setTexture(this->data->textures.get(Texture::BACKGROUND_CLOUD_TEXTURE));
    cloud.setPosition((float) this->data->window.getSize().x / 2, (float) this->data->window.getSize().y / 2);
}

void SplashState::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {

        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->window.close();
        }
    }
}

void SplashState::update(float dt) {

    cloud.setPosition(cloud.getPosition().x - 1.0f, cloud.getPosition().y);
    // Will change to splash state after 3-seconds
    if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
        this->data->machine.addState(stateRef(new MainMenuState(data)), true);
    }
}

void SplashState::draw(float dt) {
    this->data->window.clear();
    this->data->window.draw(this->background);
    this->data->window.draw(text);
    this->data->window.draw(cloud);
    this->data->window.display();
}