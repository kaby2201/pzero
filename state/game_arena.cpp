#include "game_arena.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "character.h"
#include "DEFINITIONS.hpp"


void GameArena::init() {
    header = new GameHeader(*data);

    if (!playerTexture.loadFromFile(GAME_CHARACTER))
        std::cout << "Error couldnt not load character.jpg" << std::endl;

    // Vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort
    this->character = new Character(&playerTexture, sf::Vector2u(9, 21), 0.05f, 200.0f);
}

void GameArena::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->window.close();
        }

        // just for test - adding score by pressing X on the keyboard
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            header->addScore();
            header->addHealth();
        }
        // Remove health
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            header->removeHealth();
        }
        // add more coin
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
            header->addCoin();
        }
    }
}

void GameArena::update(float dt) {
    character->Update(dt);
}

void GameArena::draw(float dt) {
    this->data->window.clear();
    character->draw(data->window);
    header->draw();
    this->data->window.display();
}