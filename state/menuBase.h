#ifndef PZERO_MENUBASE_H
#define PZERO_MENUBASE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "state.h"
#include "game.h"

class menuBase {
public:
    void menuTexture(float factorX, float factorY, float posY, gameDataRef &data);

    void inputSolver(int choice, sf::Event event, gameDataRef &data);

    void drawTexture(gameDataRef &data);

    sf::Sprite Background;
    sf::Sprite table;
    sf::Sprite exitButton;
};


#endif //MENUBASE_STATE_H
