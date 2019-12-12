#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include <list>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <objects/object.h>
#include <map/map.h>

#include "state.h"
#include "game.h"
#include "game_header.h"
#include "character.h"
#include "platform.h"


class GameArena : public State {
public:
    GameArena(gameDataRef data) : data(std::move(data)) {}

    ~GameArena()= default;

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    gameDataRef data;
    GameHeader* header;
    Character* character;
protected:
    sf::Texture playerTexture;
    sf::Sprite background;
    Platform* platform;
    Map map;
    std::list<std::shared_ptr<Object>> objects;
};


#endif //GAME_ARENA_H
