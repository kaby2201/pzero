#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class Machine;

class State{
public:
    State() {}

    virtual ~State() {};

    virtual void enter() = 0;

    virtual void render(sf::RenderWindow &window, float deltatime) = 0;

    virtual void goNext() = 0;
    virtual void goNext(Machine &context) = 0;

    virtual void handleEvents(sf::Event &event) = 0;
};

#endif