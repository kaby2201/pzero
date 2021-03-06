#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include <list>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include <objects/object.h>
#include <map/map.h>

#include "game_character/monster.h"

#include "state.h"
#include "game.h"
#include "game_header.h"
#include "game_character/character.h"
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
    Monster* monster;

    Character* character;

    sf::Texture monsterTexture;
    bool dual;

protected:
    sf::Vector2f direction = sf::Vector2f(0, 0);
    sf::Texture playerTexture;
    sf::Sprite background;
    sf::Sprite cloud;

    Map map;
    std::list<std::shared_ptr<Object>> objects;
};


#endif //GAME_ARENA_H
