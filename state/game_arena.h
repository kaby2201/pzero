#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include <list>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include "map/map.h"
#include "state.h"
#include "game.h"
#include "game_header.h"
#include "character.h"

class Object;


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
    GameHeader* header;

    Character* character;
    sf::Texture playerTexture;
    bool dual;

protected:
    std::list<std::shared_ptr<Object>> objects;
    sf::Clock clock;

    Map map;
};


#endif //GAME_ARENA_H
