#include "DEFINITIONS.hpp"
#include "game_arena.h"
#include <iostream>
#include "character.h"

#include <memory>

#include <SFML/Window.hpp>

#include "map/map.h"
#include "objects/layer.h"
#include "objects/sprite.h"
#include "pause_state.h"


void GameArena::init() {
    header = new GameHeader(*data);
    platform = new Platform(nullptr, sf::Vector2f(200, 200), sf::Vector2f(500, 200));

    if (!playerTexture.loadFromFile(GAME_CHARACTER))
        std::cout << "Error couldnt not load character.jpg" << std::endl;

    // Vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort
    this->character = new Character(&playerTexture, sf::Vector2u(9, 21), 0.05f, 90.0f);

    // Vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort

    // Load map information from JSON into object list
    if (!map.loadFromFile("data/level_1.json"))
    {
        std::cout << "Failed to load map data." << std::endl;
    }

    // Copy layer references from map object to Game list
    std::copy(map.getLayers().begin(), map.getLayers().end(), std::back_inserter(objects));

    // Copy sprite references from map object to Game list
    std::copy(map.getSprites().begin(), map.getSprites().end(), std::back_inserter(objects));

    // Double the size of the screen
    sf::View view = data->window.getDefaultView();
    view.setSize(view.getSize().x / 2, view.getSize().y / 2);
    view.setCenter(view.getCenter().x /2, view.getCenter().y / 2);
    data->window.setView(view);
    data->window.setVerticalSyncEnabled(true);

    data->window.setFramerateLimit(60);

    // Loading the background texture
    background.setTexture(data->textures.get(Texture::WELCOME_BACKGROUND_IMG));
    data->textures.load(Texture::TABLE, TABLE_BACKGROUND);

}

void GameArena::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type){
            this->data->window.close();
        }

        // Press P to pause the game
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            this->data->machine.addState(stateRef(new PauseState(data)), false);
        }

        // just for test - adding score by pressing X on the keyboard
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            header->addScore();
            header->addHealth();
        }
        // Remove health
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            header->removeHealth();
        }

        // add more coin
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            header->addCoin();
        }

        if (event.key.code == sf::Keyboard::F5){
            objects.clear();

            if (!map.loadFromFile("data/level_1.json")){
                std::cout << "Failed to reload map data." << std::endl;
            }

            std::copy(map.getLayers().begin(), map.getLayers().end(), std::back_inserter(objects));
            std::copy(map.getSprites().begin(), map.getSprites().end(), std::back_inserter(objects));
        }

    }
}


void GameArena::update(float dt) {
    character->Update(dt);
    platform->getColider().checkCollision(character->getCollider(), 0.2f);

    for (auto &item : map.getLayers()) {
        item->getColider().checkCollision(character->getCollider(), 1.0f);
    }
}

void GameArena::draw(float dt) {
    this->data->window.clear();
    this->data->window.draw(background);


    header->draw();

    // Process and render each object
    for (auto& object: objects){
        object->process(dt);
        object->draw(this->data->window);
        platform->draw(data->window);
    }
    character->draw(data->window);
    this->data->window.display();
}
