#ifndef GAME_HEADER_H
#define GAME_HEADER_H

#include <SFML/Graphics.hpp>
#include <DEFINITIONS.hpp>
#include "game.h"
#include "game_character/character.h"

class GameHeader{
public:
    explicit GameHeader(GameData &data);

    void draw();

    void addScore();

    void addHealth();

    void addIntHealth();

    void removeHealth();

    void addCoin();

    int getScore();

    int getHealth();

    std::vector<sf::Sprite> hearts;

private:
    GameData& data;
    sf::Sprite coin;
    sf::Text title, level, level1, score, coins, X;

    int intLevel = 1;
    int intCoin = 2;
    int intHealth = 4;
    int highScore = 0;
    bool alpha = false;
    bool beta = false;


protected:
    float SPACE = 5; // Mellomrom mellom hver hjerte
};
#endif //GAME_HEADER_H
