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
    sf::Text settings;
    sf::Text  titleMenu;
    sf::Sprite background;
    sf::Sprite btnPlay, btnSetting, btnHelp, btnExit, table, btnScore;

    sf::Text btn_play, btn_setting, btn_help, btn_score;
};


#endif //MAIN_MENU_STATE_H
