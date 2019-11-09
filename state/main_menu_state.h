#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Audio/Sound.hpp>
#include "game.h"

class MainMenuState : public State {
public:
    MainMenuState(gameDataRef data) : data(data) {}

    ~MainMenuState() {}

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
    sf::Text settings;
    sf::Text title, title1;
    sf::Sprite background;
    sf::Sprite btn1, btn2, btn3, btn4, table;

    sf::Text b1, b2, b3, b4;
};


#endif //PZERO_MAIN_MENU_STATE_H
