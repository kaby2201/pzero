#include <DEFINITIONS.hpp>
#include "game_over_state.h"
#include "main_menu_state.h"
#include "game_arena.h"


extern bool status;
extern int score;

void GameOverState::pause() {
    State::pause();
}

void GameOverState::init() {

    this->data->window.setView(data->window.getDefaultView());


    //SCREEN_WIDTH / 2.f - table.getGlobalBounds().width /
    table.setTexture(this->data->textures.get(Texture::TABLE));
    table.setScale(0.6,0.6);
    table.setPosition( 2 + data->window.getView().getCenter().x-table.getGlobalBounds().width/2,
                      SCREEN_HEIGHT / 2.f - table.getGlobalBounds().height/2- table.getGlobalBounds().height/5);


    this->gameOver.setString("Game over, you died!");
    gameOver.setFont(this->data->fonts.get(Font::GAME_TITLE));
    gameOver.setCharacterSize(50);
    //gameOver.setScale(0.4166,0.555);
    gameOver.setFillColor(sf::Color::Black);
    gameOver.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - gameOver.getGlobalBounds().width / 2,
                     table.getPosition().y + gameOver.getGlobalBounds().width/9);

    this->gameOverWon.setString("Congratulations, you won!");
    gameOverWon.setFont(this->data->fonts.get(Font::GAME_TITLE));
    gameOverWon.setCharacterSize(50);
    //gameOverWon.setScale(0.4166,0.555);
    gameOverWon.setFillColor(sf::Color::Black);
    gameOverWon.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - gameOverWon.getGlobalBounds().width / 2,
                         table.getPosition().y + gameOverWon.getGlobalBounds().width/9);

    this->highscore.setString("Highscore:");
    highscore.setFont(this->data->fonts.get(Font::GAME_TITLE));
    highscore.setCharacterSize(50);
    //highscore.setScale(0.4166,0.555);
    highscore.setFillColor(sf::Color::Black);
    highscore.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - highscore.getGlobalBounds().width / 2,
                          table.getPosition().y + highscore.getGlobalBounds().width/2);


    this->intScore.setString(std::to_string(score));
    intScore.setFont(this->data->fonts.get(Font::GAME_TITLE));
    intScore.setCharacterSize(50);
    //jintScore.setScale(0.4166,0.555);
    intScore.setFillColor(sf::Color::Black);
    intScore.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2 - intScore.getGlobalBounds().width / 2,
                         table.getPosition().y + table.getGlobalBounds().height / 2 - intScore.getGlobalBounds().height / 2);




    data->textures.load(Texture::PAUSE_HEADER, RESUME_BUTTON);
    tryAgain.setTexture(this->data->textures.get(Texture::PAUSE_HEADER));
    tryAgain.setScale(0.35,0.35);
    tryAgain.setPosition(data->window.getView().getCenter().x + highscore.getGlobalBounds().width/2+tryAgain.getGlobalBounds().width/1.5,
                          (table.getPosition().y + table.getGlobalBounds().height / 2 + highscore.getGlobalBounds().width/2)-tryAgain.getGlobalBounds().width/4);

    exit.setTexture(this->data->textures.get(Texture::BUTTON_EXIT));
    exit.setScale(0.5,0.5);
    exit.setPosition(data->window.getView().getCenter().x-highscore.getGlobalBounds().width,
                     (table.getPosition().y + table.getGlobalBounds().height / 2 + highscore.getGlobalBounds().width/2)-tryAgain.getGlobalBounds().width/4);




}

void GameOverState::resume() {
    State::resume();
}

void GameOverState::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event))
    {
            if (this->data->input.isSpriteClicked(this->exit, sf::Mouse::Left, data->window)) {
                this->data->machine.addState(stateRef(new MainMenuState(data)), true);
            }

        if (this->data->input.isSpriteClicked(this->tryAgain, sf::Mouse::Left, data->window)) {
            this->data->machine.addState(stateRef(new GameArena(data)), true);
        }


    }
    }



void GameOverState::draw(float dt) {
    //data->window.clear();
    data->window.draw(table);
    if(status)
    {data->window.draw(gameOverWon);
    }
    else if(!status)
    {data->window.draw(gameOver);
    }
    data->window.draw(highscore);
    data->window.draw(intScore);
    data->window.draw(tryAgain);
    data->window.draw(exit);
    data->window.display();

}

void GameOverState::update(float dt) {

}
