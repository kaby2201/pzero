#ifndef GAME_H
#define GAME_H

#include <DEFINITIONS.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include "config/config.h"

class Object;

class Game {
public:
    bool init();
    void run();

protected:
  //  bool gameTick(sf::RenderWindow &window, std::list<std::shared_ptr<Object>> &objects, float deltaTime);

    // List of game objects. Should of course be put somewhere else in a bigger game
    std::list<std::shared_ptr<Object>> objects;
    sf::Clock clock;

    sf::RenderWindow window;

    //Map map;

    // Time
    sf::Clock tickClock;

    bool focus = true;
    bool fullscreenModeSwitch = false;
    bool windowedModeSwitch = false;
};

#endif
