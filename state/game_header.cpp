#include <iostream>
#include "game_header.h"

extern int counter;

GameHeader::GameHeader(GameData &data) : data(data) {

    // Legger til live

    this->data.textures.load(Texture::HEART, HEART_IMAGE);
    for (int i = 1; i <= intHealth; ++i)
        addHealth();

    this->level.setString("LEVEL ");
    level.setFont(this->data.fonts.get(Font::GAME_TITLE));
    level.setCharacterSize(50);
    level.setFillColor(sf::Color::White);
    level.setPosition(data.window.getSize().x-300,0);

    this->level1.setString(std::to_string(intLevel));
    level1.setFont(this->data.fonts.get(Font::GAME_TITLE));
    level1.setCharacterSize(50);
    level1.setFillColor(sf::Color::White);
    level1.setPosition(SCREEN_WIDTH-50-100,0);

    this->score.setString(std::to_string(highScore));
    score.setFont(this->data.fonts.get(Font::GAME_TITLE));
    score.setCharacterSize(50);
    score.setFillColor(sf::Color::White);
    score.setPosition(SCREEN_WIDTH-200-50,50);

    this->data.textures.load(Texture::COIN, COIN_IMAGE);
    coin.setTexture(this->data.textures.get(Texture::COIN));
    coin.setScale(0.025, 0.025);
    coin.setPosition(25,10);

    this->X.setString("X");
    X.setFont(this->data.fonts.get(Font::GAME_TITLE));
    X.setCharacterSize(35);
    X.setFillColor(sf::Color::White);
    X.setPosition(75,13);

    this->coins.setString(std::to_string(intCoin));
    coins.setFont(this->data.fonts.get(Font::GAME_TITLE));
    coins.setCharacterSize(50);
    coins.setFillColor(sf::Color::White);
    coins.setPosition(115,3);

    title.setFillColor(sf::Color::Red);
    title.setFont(data.fonts.get(Font::GAME_TITLE));
}

void GameHeader::draw() {
    for(int i = 0; i < intHealth; i++)
    {data.window.draw(hearts[i]);}

    data.window.draw(level);
    data.window.draw(level1);
    data.window.draw(score);
    data.window.draw(X);
    data.window.draw(coins);
    data.window.draw(coin);
}

void GameHeader::addScore() {
    highScore += 10;
    this->score.setString(std::to_string(highScore));
}

void GameHeader::addHealth() {
    SPACE +=25;
    sf::Sprite sprite(this->data.textures.get(Texture::HEART));
    sprite.setScale(0.05, 0.05);
    sprite.setPosition(0+SPACE, 60);
    hearts.push_back(sprite);
}



void GameHeader::removeHealth() {
    std::cout<<"Removed health!"<<std::endl;
        intHealth -=1;
}

void GameHeader::addCoin() {
    intCoin +=1;
    this->coins.setString(std::to_string(intCoin));
}

int GameHeader::getScore()
{
    return highScore;
}

int GameHeader::getHealth()
{
    return intHealth;
}

void GameHeader::addIntHealth()
{
    intHealth+=1;
}

