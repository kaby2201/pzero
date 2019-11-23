//
// Created by ALI on 22/11/2019.
//

#ifndef PZERO_GAME_ARENA_GUI_H
#define PZERO_GAME_ARENA_GUI_H


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
    int score;
    unsigned int currentHP;



};


#endif //PZERO_GAME_ARENA_GUI_H
