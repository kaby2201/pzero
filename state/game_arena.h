#ifndef GAME_ARENA_H
#define GAME_ARENA_H


#include "state.h"
#include <SFML/Graphics.hpp>

class GameArena : public State{
public:
    GameArena(){}

    void pause() override {
        State::pause();
    }

    void init() override {

    }

    void resume() override {
        State::resume();
    }

    void handleInput() override {

    }

    void draw(float dt) override {

    }

    void update(float dt) override {

    }

private:
    sf::RenderTexture recTexture;
};


#endif //GAME_ARENA_H
