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

    void addIntHealth();

    void removeHealth();

    void addCoin();

    int getScore();

    int getHealth();


private:
    sf::View view1;
    GameData& data;
    sf::Sprite coin;
    sf::Text title, level, level1, score, coins, X;

    int intLevel = 1;
    int intCoin = 2;
    int intHealth = 4;
    int highScore = 0;
    bool alpha = false;
    bool beta = false;

    std::vector<sf::Sprite> hearts;

protected:
    float SPACE = 25; // Mellomrom mellom hver hjerte
};
#endif //GAME_HEADER_H
