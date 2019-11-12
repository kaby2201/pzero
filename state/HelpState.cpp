#include "HelpState.h"

void HelpState::init() {

}

void HelpState::handleInput() {

}

void HelpState::update(float dt) {

}

void HelpState::draw(float dt) {
    data->window.clear();
    data->window.display();
}

void HelpState::pause() {
    State::pause();
}

void HelpState::resume() {
    State::resume();
}