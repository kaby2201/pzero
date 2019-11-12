#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Audio/Sound.hpp>
#include "game.h"

class HelpState : public State {
public:
    HelpState(gameDataRef data) : data(data) {}

    ~HelpState() {}

    void init();

    void handleInput();

    void update(float dt) override;

    void draw(float dt) override;

    void pause() override;

    void resume() override;

private:
    gameDataRef data;
};


#endif //PZERO_MAIN_MENU_STATE_H
