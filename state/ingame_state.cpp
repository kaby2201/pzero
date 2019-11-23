#include "ingame_state.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "DEFINITIONS.hpp"
#include "game.h"
#include "main_menu_state.h"


void GameArena::init() {
    title.setString("the best game ever...?");
    title.setFillColor(sf::Color::Green);
    title.setFont(data->fonts.get(Font::GAME_TITLE));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::Texture playerTexture;

    if (!playerTexture.loadFromFile(GAME_CHARACTER)) {
        std::cout << "Error couldnt not load character.jpg" << std::endl;
    }
  //  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!", sf::Style::Default, settings);
//    this->data->textures.load(Texture::TABLE, );

    Player player(&playerTexture, sf::Vector2u(9, 21), 0.05f,150.0f);  //vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort
    //- vi går gjennom animasjonen
    float deltaTime = 0.0f;
    sf::Clock clock;
    while (data->window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            switch(event.type)
            {
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    {
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        this->data->machine.addState(stateRef(new MainMenuState(data)), true);
                    }
                case sf::Event::Closed:
                    if (event.type == sf::Event::Closed) {
                        this->data->window.close();
                    }
                default:
                    break;
            }
        }
        player.Update(deltaTime);
        data->window.clear();
        player.Draw(data->window);
        data->window.display();
    }
}

void GameArena::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->window.close();
        }
    }
}

void GameArena::update(float dt) {

}

void GameArena::draw(float dt) {
    this->data->window.clear();
    this->data->window.draw(title);
    this->data->window.display();
}