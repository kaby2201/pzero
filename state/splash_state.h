#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "state.h"

class SplashState : public State {
public:
    SplashState(gameDataRef data);

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    gameDataRef data;
    sf::Clock clock;
    sf::Text text;

    sf::Sprite background;
    sf::Sprite cloud;
};


#endif //SPLASH_STATE_H
