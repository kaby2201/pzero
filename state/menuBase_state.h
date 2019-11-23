#ifndef PZERO_MENUBASE_STATE_H
#define PZERO_MENUBASE_STATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include <iostream>
#include "state.h"
#include "game.h"

class MenuBaseState {
public:
    //MenuBaseState(gameDataRef data)  : data(std::move(data)){}


    void menuTexture(float factorX, float factorY, float posY, gameDataRef &DATA);

    void inputSolver(int choice, sf::Event event, gameDataRef &DATA);

    void drawTexture(gameDataRef &DATA);

    //gameDataRef data;
    sf::Sprite Background;
    sf::Sprite table;
    sf::Sprite exitButton;
};


#endif //PZERO_MENUBASE_STATE_H
