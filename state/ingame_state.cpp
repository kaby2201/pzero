#include "ingame_state.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "DEFINITIONS.hpp"
#include "game.h"
#include "main_menu_state.h"


void GameArena::init() {
    intLevel = 1;
    intCoin = 0;
    highscore = 0;
    intHealth = 4;
    title.setString("the best game ever...?");
    title.setFillColor(sf::Color::Green);
    title.setFont(data->fonts.get(Font::GAME_TITLE));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::Texture playerTexture;

    background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));

    this->level.setString("LEVEL ");
    level.setFont(this->data->fonts.get(Font::GAME_TITLE));
    level.setCharacterSize(50);
    level.setFillColor(sf::Color::White);
    level.setPosition(SCREEN_WIDTH-200-100,0);

    this->level1.setString(std::to_string(intLevel));
    level1.setFont(this->data->fonts.get(Font::GAME_TITLE));
    level1.setCharacterSize(50);
    level1.setFillColor(sf::Color::White);
    level1.setPosition(SCREEN_WIDTH-50-100,0);

    this->score.setString(std::to_string(highscore));
    score.setFont(this->data->fonts.get(Font::GAME_TITLE));
    score.setCharacterSize(50);
    score.setFillColor(sf::Color::White);
    score.setPosition(SCREEN_WIDTH-200-50,50);

    this->data->textures.load(Texture::COIN, COIN_IMAGE);
    coin.setTexture(this->data->textures.get(Texture::COIN));
    coin.setScale(0.025, 0.025);
    coin.setPosition(25,10);

    this->x.setString("x");
    x.setFont(this->data->fonts.get(Font::GAME_TITLE));
    x.setCharacterSize(35);
    x.setFillColor(sf::Color::White);
    x.setPosition(75,13);

    this->coins.setString(std::to_string(intCoin));
    coins.setFont(this->data->fonts.get(Font::GAME_TITLE));
    coins.setCharacterSize(50);
    coins.setFillColor(sf::Color::White);
    coins.setPosition(115,3);

    this->data->textures.load(Texture::HEART, HEART_IMAGE);
    heart1.setTexture(this->data->textures.get(Texture::HEART));
    heart1.setScale(0.05, 0.05);
    heart1.setPosition(25,60);

    heart2.setTexture(this->data->textures.get(Texture::HEART));
    heart2.setScale(0.05, 0.05);
    heart2.setPosition(60,60);

    heart3.setTexture(this->data->textures.get(Texture::HEART));
    heart3.setScale(0.05, 0.05);
    heart3.setPosition(95,60);

    heart4.setTexture(this->data->textures.get(Texture::HEART));
    heart4.setScale(0.05, 0.05);
    heart4.setPosition(130,60);

    hearts.push_back(heart1); hearts.push_back(heart2); hearts.push_back(heart3); hearts.push_back(heart4);

    if (!playerTexture.loadFromFile(GAME_CHARACTER)) {
        std::cout << "Error couldnt not load character.jpg" << std::endl;
    }
  //  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!", sf::Style::Default, settings);
//    this->data->textures.load(Texture::TABLE, );




    player player(&playerTexture, sf::Vector2u(9, 21), 0.05f,150.0f);  //vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort
    //- vi går gjennom animasjonen
    float deltaTime = 0.0f;
    sf::Clock clock;
    while (data->window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        sf::Event event{};
        while (this->data->window.pollEvent(event)) {
            switch(event.type)
            {
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    {
                        highscore += 10;
                        score.setString(std::to_string(highscore));
                        intHealth--;


                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        this->data->machine.addState(stateRef(new MainMenuState(data)), true);
                    }
                case sf::Event::Closed:
                    if (event.type == sf::Event::Closed) {
                        this->data->window.close();
                    }
                default:
                    break;
            }
        }
        player.Update(deltaTime);
        data->window.clear();
        data->window.draw(background);
        data->window.draw(level);
        data->window.draw(level1);
        data->window.draw(score);
        data->window.draw(x);
        data->window.draw(coins);
        data->window.draw(coin);


        for(int i = 0; i < intHealth; i++)
        {
            data->window.draw(hearts[i]);
        }
        /*switch(intHealth)
        {
            case 4:
                data->window.draw(heart1);
                data->window.draw(heart2);
                data->window.draw(heart3);
                data->window.draw(heart4);

            case 3:
                data->window.draw(heart1);
                data->window.draw(heart2);
                data->window.draw(heart3);

            case 2:
                data->window.draw(heart1);
                data->window.draw(heart2);

            case 1:
                data->window.draw(heart1);

            default:
                break;

        }*/


        player.Draw(data->window);
        data->window.display();
    }
}

void GameArena::handleInput() {
    sf::Event event{};

    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->data->window.close();
        }
    }
}

void GameArena::update(float dt) {
}

void GameArena::draw(float dt) {
    this->data->window.clear();
    this->data->window.draw(level);
    this->data->window.draw(title);
    this->data->window.display();
}