#ifndef PZERO_MENU_BASE_H
#define PZERO_MENU_BASE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "state.h"
#include "game.h"

class MenuBase {
public:
    void menuTexture(float factorX, float factorY, float posY, gameDataRef &data);

    void inputSolver(int choice, sf::Event event, gameDataRef &data);

    void drawTexture(gameDataRef &data);

    sf::Sprite Background;
    sf::Sprite table, cloud;
    sf::Sprite exitButton;
};


#endif //MENUBASE_STATE_H
