#include "menu_base.h"
#include "DEFINITIONS.hpp"
#include "main_menu_state.h"

void MenuBase::menuTexture(float factorX, float factorY, float posY, gameDataRef &data){

    // Loading the background texture
    Background.setTexture(data->textures.get(Texture::WELCOME_BACKGROUND_IMG));
    data->textures.load(Texture::TABLE, TABLE_BACKGROUND);

    table.setTexture(data->textures.get(Texture::TABLE));
    table.setScale(factorX, factorY);
    table.setPosition(SCREEN_WIDTH / 2.f - table.getGlobalBounds().width / 2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height / 2);

    data->textures.load(Texture::BUTTON_EXIT, EXIT_MENU_BUTTON);
    exitButton.setTexture(data->textures.get(Texture::BUTTON_EXIT));

    exitButton.setScale(0.4, 0.4);
    exitButton.setPosition(table.getPosition().x + table.getGlobalBounds().width
    / 2 - exitButton.getGlobalBounds().width / 2, table.getPosition().y + posY);

    cloud.setTexture(data->textures.get(Texture::BACKGROUND_CLOUD_TEXTURE));
    cloud.setPosition((float) data->window.getSize().x / 2, (float) data->window.getSize().y / 2);
}

void MenuBase::inputSolver(int choice, sf::Event event, gameDataRef &data){
    if (data->input.isSpriteClicked(this->exitButton, sf::Mouse::Left, data->window)) {
        if(choice == 1)
            data->window.close();
        else if(choice == 2)
            data->machine.addState(stateRef(new MainMenuState(data)), true);
    }

    if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        if(choice == 1)
            data->window.close();
        else if(choice == 2)
            data->machine.addState(stateRef(new MainMenuState(data)), true);
    }

}

void MenuBase::drawTexture(gameDataRef &data){
    cloud.setPosition(cloud.getPosition().x - 1.0f, cloud.getPosition().y);
    data->window.draw(Background);
    data->window.draw(cloud);
    data->window.draw(table);
    data->window.draw(exitButton);
}

