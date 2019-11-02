#include "in_game.h"

void InGame::pause() {
    State::pause();
}

void InGame::init() {
    text.setFont(this->data->fonts.get(Font::GAME_TITLE));
    text.setString("Dette er bare test");
    text.setPosition(0.f, 0.f);
}

void InGame::resume() {
    State::resume();
}

void InGame::handleInput() {

}

void InGame::draw(float dt) {
    this->data->window.clear();
    this->data->window.draw(text);
    this->data->window.display();
}

void InGame::update(float dt) {

}
