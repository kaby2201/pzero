#include "ingame_state.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "character.h"
#include "DEFINITIONS.hpp"
#include "game.h"
#include "main_menu_state.h"

void ResizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(SCREEN_HEIGHT * aspectRatio, SCREEN_HEIGHT );
}

void GameArena::init() {
    intLevel = 1;
    intCoin = 0;
    highscore = 0;
    intHealth = 4;

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

    unsigned int health = 4;
    int x = 98;

    title.setFillColor(sf::Color::Red);
    title.setFont(data->fonts.get(Font::GAME_TITLE));

    sf::View view (sf::Vector2f(SCREEN_WIDTH/2,SCREEN_HEIGHT/2), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    sf::RectangleShape rectangle(sf::Vector2f(2000.f, 50.f));
    rectangle.setSize(sf::Vector2f(1000.f,25.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(300,565);
    this->data->window.setFramerateLimit(60);


    if(!spikeTexture.loadFromFile(SPIKES)) {
        std::cout << "Error couldnt not load spikes" << std::endl;
    }
    spikes.setTexture(spikeTexture);
    spikes.setPosition(1000,750);
    spikes.setScale(0.2f,0.2f);

     this->data->textures.load(Texture::WELCOME_BACKGROUND_IMG, SPLASH_SCREEN_BACKGROUND);
     background.setTexture(this->data->textures.get(Texture::WELCOME_BACKGROUND_IMG));
     background.setPosition(0,0);



    if (!playerTexture.loadFromFile(GAME_CHARACTER)) {
        std::cout << "Error couldnt not load character.jpg" << std::endl;
    }

    character character(&playerTexture, sf::Vector2u(9, 21), 0.05f,200.0f);  //vi har 21 rader og opp til 13 animasjoner og switchtime bestemmer hvor fort

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

                        this->data->machine.addState(stateRef(new MainMenuState(data)), true);

                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

                    }
                case sf::Event::Closed:
                    if (event.type == sf::Event::Closed) {
                        this->data->window.close();
                    }
                case sf::Event::Resized:
                    ResizeView(data->window, view);

                default:
                    break;
            }
        }

        title.setString("Health:"+ std::to_string(health));
        character.Update(deltaTime);
        data->window.setView(view);

        data->window.clear();

        data->window.draw(background);
        data->window.draw(level);
        data->window.draw(level1);
        data->window.draw(score);
        //data->window.draw(x);
        data->window.draw(coins);
        data->window.draw(coin);


        for(int i = 0; i < intHealth; i++){
            data->window.draw(hearts[i]);
        }


        this->data->window.draw(this->background);
        if(character.GetPositions().x > SCREEN_WIDTH/2) {
            view.setCenter(character.GetPositions().x, SCREEN_HEIGHT/2);
            title.setPosition(character.GetPositions().x-SCREEN_WIDTH_MIDDLE, 0 );

        }
        if(spikes.getGlobalBounds().contains(character.GetPositions())){
            x++;
            if(x > 100) {
                health--;
                x = 0;
            }
        }
        data->window.draw(title);
        character.Draw(data->window);
        data->window.draw(spikes);
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