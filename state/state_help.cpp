#include <DEFINITIONS.hpp>
#include "state_help.h"
#include "main_menu_state.h"

void state_help::init() {
    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));
    table.setTexture(this->data->textures.get(Texture::TABLE));
    table.setScale(0.7, 0.6);
    table.setPosition(SCREEN_WIDTH / 2.f - table.getGlobalBounds().width / 2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height / 2);

    this->data->textures.load(Texture::LEFT_POINTER, POINTER_LEFT);
    leftPointer.setTexture(this->data->textures.get(Texture::LEFT_POINTER));
    leftPointer.setPosition(table.getPosition().x - leftPointerText.getGlobalBounds().width + 550, table.getPosition().y +60-40);

    this->data->textures.load(Texture::RIGHT_POINTER, POINTER_RIGHT);
    rightPointer.setTexture(this->data->textures.get(Texture::RIGHT_POINTER));
    rightPointer.setPosition(table.getPosition().x  - leftPointerText.getGlobalBounds().width + 550, table.getPosition().y + 240-70);

    this->data->textures.load(Texture::SPACEBAR, SPACE_BAR);
    spacebar.setTexture(this->data->textures.get(Texture::SPACEBAR));
    spacebar.setPosition(table.getPosition().x  - leftPointerText.getGlobalBounds().width + 550, table.getPosition().y + 360-60);

    exit.setTexture(this->data->textures.get(Texture::BUTTON_EXIT));
    exit.setScale(0.13, 0.13);
    exit.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - exit.getGlobalBounds().width / 2,
                     table.getPosition().y + 395);

    this->leftPointerText.setString("Move left");
    leftPointerText.setFont(this->data->fonts.get(Font::GAME_TITLE));
    leftPointerText.setCharacterSize(60);
    leftPointerText.setFillColor(sf::Color::Black);
    leftPointerText.setPosition(table.getPosition().x  - leftPointer.getGlobalBounds().width + 250+10, table.getPosition().y + 80+35-40);
    //leftPointer.setPosition(table.getPosition().x  - leftPointer.getGlobalBounds().width + 250, table.getPosition().y + 80);

    this->rightPointerText.setString("Move right");
    rightPointerText.setFont(this->data->fonts.get(Font::GAME_TITLE));
    rightPointerText.setCharacterSize(60);
    rightPointerText.setFillColor(sf::Color::Black);
    rightPointerText.setPosition(table.getPosition().x - leftPointer.getGlobalBounds().width + 250+10, table.getPosition().y + 240+35-50);
    //rightPointer.setPosition(table.getPosition().x  - rightPointer.getGlobalBounds().width + 250, table.getPosition().y + 240);


    this->spacebarText.setString("Jump");
    spacebarText.setFont(this->data->fonts.get(Font::GAME_TITLE));
    spacebarText.setCharacterSize(60);
    spacebarText.setFillColor(sf::Color::Black);
    spacebarText.setPosition(table.getPosition().x - leftPointer.getGlobalBounds().width + 250+10, table.getPosition().y + 360+35-40);
    //spacebar.setPosition(table.getPosition().x  - rightPointer.getGlobalBounds().width + 250, table.getPosition().y + 400);

    this->title1.setString("HELP");
    title1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    title1.setCharacterSize(150);
    title1.setFillColor(sf::Color::Black);
    title1.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - title1.getGlobalBounds().width / 2,
                       table.getPosition().y - 140);

}

void state_help::handleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event))
    {
        if (this->data->input.isSpriteClicked(this->exit, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new MainMenuState(data)), true);
        }
    }

}

void state_help::update(float dt) {

}

void state_help::draw(float dt) {
    data->window.clear();
    data->window.draw(background);
    data->window.draw(table);
    data->window.draw(leftPointer);
    data->window.draw(rightPointer);
    data->window.draw(spacebar);
    data->window.draw(exit);
    data->window.draw(title1);
    data->window.draw(leftPointerText);
    data->window.draw(rightPointerText);
    data->window.draw(spacebarText);
    data->window.display();
}

void state_help::pause() {
    State::pause();
}

void state_help::resume() {
    State::resume();
}
