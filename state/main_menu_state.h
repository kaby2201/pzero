#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Audio/Sound.hpp>
#include <utility>
#include "game.h"
#include "menu_base.h"

class MainMenuState : public State, MenuBase {
public:
    MainMenuState(gameDataRef data) : data(std::move(data)) {};

    ~MainMenuState() {}

    void init();

    void handleInput();

    void update(float dt) override;

    void draw(float dt) override;

    void pause() override;

    void resume() override;

private:
    gameDataRef data;
    sf::Sprite btnPlay, btnSetting, btnHelp, btnScore;

    sf::Text settings, titleMenu, btn_play, btn_setting, btn_help, btn_score;
};


#endif //MAIN_MENU_STATE_H
