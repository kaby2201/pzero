#ifndef PZERO_STATE_HELP_H
#define PZERO_STATE_HELP_H

#include <SFML/Audio/Sound.hpp>
#include "game.h"
#include "menuBase_state.h"

class state_help : public State, MenuBaseState{
public:
    state_help(gameDataRef data) : data(data) {}

    ~state_help() {}

    void init();

    void handleInput();

    void update(float dt) override;

    void draw(float dt) override;

    void pause() override;

    void resume() override;

private:
    gameDataRef data;
    sf::Texture texture;
    sf::Sprite background;
    //sf::Sprite table;
    sf::Sprite spacebar;
    sf::Sprite leftPointer;
    sf::Sprite rightPointer;
    sf::Sprite leftrightPointer;
    sf::Sprite exit;
    sf::Text leftPointerText;
    sf::Text rightPointerText;
    sf::Text leftRightPointerText;
    sf::Text spacebarText;
    sf::Text title1;
};


#endif //PZERO_STATE_HELP_H
