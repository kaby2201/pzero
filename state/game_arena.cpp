#include "game_arena.h"

void GameArena::init() {
    title.setString("the best game ever...?");
    title.setFillColor(sf::Color::Green);
    title.setFont(data->fonts.get(Font::GAME_TITLE));

//    ParticleSystem particles(1000);
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