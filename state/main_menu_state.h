#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H


#include "game.h"

class MainMenuState : public State {
public:
    MainMenuState(gameDataRef data) : data(data){}

    ~MainMenuState(){}

    void init();

    void handleInput();

    void update(float dt) override;

    void draw(float dt) override;

    void pause() override;

    void resume() override;

private:
    gameDataRef data;
    sf::Sprite b;
    sf::Sprite button;
    sf::Sprite title;
};


#endif //PZERO_MAIN_MENU_STATE_H
