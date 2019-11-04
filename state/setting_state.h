#ifndef SETTING_STATE_H
#define SETTING_STATE_H

#include <SFML/Graphics.hpp>
#include "game.h"
#include "state.h"
#include <iostream>

class SettingState : public State{
public:
    SettingState(gameDataRef data)  : data(std::move(data)){}

    void pause() override;

    void init() override;

    void resume() override;

    void handleInput() override;

    void draw(float dt) override;

    void update(float dt) override;

private:
    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    gameDataRef data;
    sf::Sprite background;
    sf::Sprite table;
    sf::Sprite muteOff;
    sf::Sprite muteOn;
    sf::Sprite button;
    std::vector<sf::Sprite> buttons;
    bool alpha = false;
};


#endif //PZERO_SETTING_STATE_H
