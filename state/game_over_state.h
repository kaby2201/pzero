#ifndef PZERO_GAME_OVER_STATE_H
#define PZERO_GAME_OVER_STATE_H

#include "state.h"
#include "game.h"
#include "game_header.h"

class GameOverState : public State {
public:
    GameOverState(gameDataRef data) : data(std::move(data)) {};

    void pause() override;

    void init() override;

    void resume() override;

    void handleInput() override;

    void draw(float dt) override;

    void update(float dt) override;

private:
    sf::View view;
    gameDataRef data;
    sf::Sprite table;
    sf::Sprite tryAgain;
    sf::Sprite exit;
    sf::Text gameOver;
    sf::Text gameOverWon;
    sf::Text highscore;
    sf::Text intScore;
};


#endif //PZERO_GAME_OVER_STATE_H
