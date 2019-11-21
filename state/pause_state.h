#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H


#include "state.h"
#include "game.h"

class PauseState : public State {
public:
    PauseState(gameDataRef data);

    ~PauseState(){}

    void init();

    void handleInput();

    void update(float dt) override;

    void draw(float dt) override;

    void pause() override;

    void resume() override;

private:
    gameDataRef data;
    sf::Sprite pauseButton;
};


#endif //PZERO_PAUSE_STATE_H
