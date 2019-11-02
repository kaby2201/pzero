#ifndef IN_GAME_H
#define IN_GAME_H

#include <SFML/Graphics.hpp>
#include "game.h"
#include "state.h"

class InGame : public State {
public:
    InGame(gameDataRef data) : data(std::move(data)){}
    void pause() override;

    void init() override;

    void resume() override;

    void handleInput() override;

    void draw(float dt) override;

    void update(float dt) override;

private:
    gameDataRef data;
    sf::Text text;
    sf::Font font;
};


#endif //IN_GAME_H
