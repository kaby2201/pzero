#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Audio/Sound.hpp>
#include "game.h"
#include "menuBase_state.h"

class MainMenuState : public State, MenuBaseState {
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
    sf::Text settings;
    sf::Text  titleMenu;
    sf::Sprite btnPlay, btnSetting, btnHelp, btnScore;

    sf::Text btn_play, btn_setting, btn_help, btn_score;
};


#endif //PZERO_MAIN_MENU_STATE_H
