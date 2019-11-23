//
// Created by Sultan on 11/21/2019.
//

#include "menuBase_state.h"
#include "DEFINITIONS.hpp"
#include "main_menu_state.h"

void MenuBaseState::menuTexture(float factorX, float factorY, float posY, gameDataRef &DATA)
{
    Background.setTexture(DATA->textures.get(Texture::WELCOME_BACKGROUND_IMG));
    DATA->textures.load(Texture::TABLE, TABLE_BACKGROUND);
    table.setTexture(DATA->textures.get(Texture::TABLE));
    table.setScale(factorX, factorY);
    table.setPosition(SCREEN_WIDTH / 2.f - table.getGlobalBounds().width / 2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height / 2);
    DATA->textures.load(Texture::BUTTON_EXIT, EXIT_MENU_BUTTON);
    exitButton.setTexture(DATA->textures.get(Texture::BUTTON_EXIT));
    exitButton.setScale(0.4, 0.4);
    exitButton.setPosition(table.getPosition().x + table.getGlobalBounds().width
                                                   / 2 - exitButton.getGlobalBounds().width / 2, table.getPosition().y + posY);

}

void MenuBaseState::inputSolver(int choice, sf::Event event, gameDataRef &DATA)
{
    if (DATA->input.isSpriteClicked(this->exitButton, sf::Mouse::Left, DATA->window)) {

        if(choice == 1)
        {
            DATA->window.close();
        }
        else if(choice == 2)

        {
            DATA->machine.addState(stateRef(new MainMenuState(DATA)), true);
        }
    }
    if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

        if(choice == 1)
        {
            DATA->window.close();
        }
        else if(choice == 2)

        {
            DATA->machine.addState(stateRef(new MainMenuState(DATA)), true);
        }
    }

}

void MenuBaseState::drawTexture(gameDataRef &DATA)
{
    DATA->window.draw(Background);
    DATA->window.draw(table);
    DATA->window.draw(exitButton);
}

