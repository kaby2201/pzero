#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include "state.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <utility>
#include <state/in_game/include/WorldManager.h>

class GameArena : public State {
public:
    GameArena(gameDataRef data) : data(std::move(data)) {}

    ~GameArena(){}

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    WorldManager worldMgr;


    gameDataRef data;
};


#endif //GAME_ARENA_H
