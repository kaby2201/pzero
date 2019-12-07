#ifndef GAME_HEADER_H
#define GAME_HEADER_H

#include <SFML/Graphics.hpp>
#include <DEFINITIONS.hpp>
#include "game.h"

class GameHeader{
public:
    explicit GameHeader(GameData &data);

    void draw();

    void addScore();

    void addHealth();

    void removeHealth();

    void addCoin();

private:
    GameData& data;
    sf::Sprite coin;
    sf::Text title, level, level1, score, coins, X;

    int intLevel = 1;
    int intCoin = 2;
    int highScore = 0;
    int intHealth = 4;

    std::vector<sf::Sprite> hearts;

protected:
    float SPACE = 25; // Mellomrom mellom hver hjerte
};
#endif //GAME_HEADER_H
