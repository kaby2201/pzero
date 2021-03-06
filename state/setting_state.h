#ifndef SETTING_STATE_H
#define SETTING_STATE_H

#include <SFML/Graphics.hpp>
#include "game.h"
#include "state.h"
#include "menu_base.h"
#include <iostream>

class SettingsState : public State, MenuBase{
public:
    SettingsState(gameDataRef data)  : data(std::move(data)){}

    void pause() override;

    void init() override;

    void resume() override;

    void handleInput() override;

    void draw(float dt) override;

    void update(float dt) override;

private:
    gameDataRef data;
    sf::Text text;
    sf::Text text1;
    sf::Text Vnumber;
    sf::Text title;
    sf::Sprite background;
    sf::Sprite muteOff;
    sf::Sprite muteOn;
    sf::Sprite Vinrease;
    sf::Sprite Vdecrease;

    bool alpha = false;
    int num;
};


#endif //PZERO_SETTING_STATE_H
