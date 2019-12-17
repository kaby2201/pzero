#include <DEFINITIONS.hpp>
#include "game_over_state.h"
#include "main_menu_state.h"

void GameOverState::pause() {
    State::pause();
}

void GameOverState::init() {
    //SCREEN_WIDTH / 2.f - table.getGlobalBounds().width /
    header = new GameHeader(*data);
    table.setTexture(this->data->textures.get(Texture::TABLE));
    table.setScale(0.3,0.4);
    table.setPosition( 2 + data->window.getView().getCenter().x-table.getGlobalBounds().width/2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height-table.getGlobalBounds().height/2);


    this->gameOver.setString("Game over, you died!");
    gameOver.setFont(this->data->fonts.get(Font::GAME_TITLE));
    gameOver.setCharacterSize(30);
    gameOver.setFillColor(sf::Color::Black);
    gameOver.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - gameOver.getGlobalBounds().width / 2,
                     table.getPosition().y + gameOver.getGlobalBounds().width/9);

    this->highscore.setString("Highscore:");
    highscore.setFont(this->data->fonts.get(Font::GAME_TITLE));
    highscore.setCharacterSize(30);
    highscore.setFillColor(sf::Color::Black);
    highscore.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - highscore.getGlobalBounds().width / 2,
                          table.getPosition().y + highscore.getGlobalBounds().width/2);


    this->intScore.setString(std::to_string(header->getScore()));
    intScore.setFont(this->data->fonts.get(Font::GAME_TITLE));
    intScore.setCharacterSize(30);
    intScore.setFillColor(sf::Color::Black);
    intScore.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - intScore.getGlobalBounds().width / 2,
                         table.getPosition().y + table.getGlobalBounds().height / 2 - intScore.getGlobalBounds().height / 2);




    data->textures.load(Texture::PAUSE_HEADER, RESUME_BUTTON);
    tryAgain.setTexture(this->data->textures.get(Texture::PAUSE_HEADER));
    tryAgain.setScale(0.2,0.2);
    tryAgain.setPosition(data->window.getView().getCenter().x+table.getGlobalBounds().width  - (tryAgain.getGlobalBounds().width + (intScore.getGlobalBounds().width/2)*3 ) ,
                          (table.getPosition().y + table.getGlobalBounds().height / 2 -
                           intScore.getGlobalBounds().height / 2) + intScore.getGlobalBounds().width * 3);

    exit.setTexture(this->data->textures.get(Texture::BUTTON_EXIT));
    exit.setScale(0.25,0.33);
    exit.setPosition(data->window.getView().getCenter().x-highscore.getGlobalBounds().width,
                     (table.getPosition().y + table.getGlobalBounds().height / 2 -
                     intScore.getGlobalBounds().height / 2) + intScore.getGlobalBounds().width * 3);





}

void GameOverState::resume() {
    State::resume();
}

void GameOverState::handleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event))
    {
        if (this->data->input.isSpriteClicked(this->exit, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new MainMenuState(data)), true);
        }
    }
    }



void GameOverState::draw(float dt) {
    //data->window.clear();

    data->window.draw(table);
    data->window.draw(gameOver);
    data->window.draw(highscore);
    data->window.draw(intScore);
    data->window.draw(tryAgain);
    data->window.draw(exit);
    data->window.display();

}

void GameOverState::update(float dt) {

}
