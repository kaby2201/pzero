#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include "state.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <utility>

class GameArena : public State {
public:
    GameArena(gameDataRef data) : data(std::move(data)) {}

    ~GameArena(){}

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    gameDataRef data;
    sf::Text title;
    //ParticleSystem ParticleSystem;
    sf::RectangleShape box;
};


#endif //GAME_ARENA_H