#ifndef GAME_ARENA_H
#define GAME_ARENA_H

#include "state.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <utility>

#include <vector>

#include "character.h"


class GameArena : public State {
public:
    GameArena(gameDataRef data) : data(std::move(data)) {}

    ~GameArena(){}

    void init();

    void handleInput();

    void update(float dt);

    void draw(float dt);

private:
    gameDataRef data;
    sf::Sprite coin;
    sf::Sprite heart1;
    sf::Sprite heart2;
    sf::Sprite heart3;
    sf::Sprite heart4;
    sf::Sprite background;
    sf::Text title;
    sf::Text level;
    sf::Text level1;
    sf::Text score;
    sf::Text coins;
    sf::Text x;

    int highscore;
    int intLevel;
    int intCoin;
    int intHealth;

    std::vector<sf::Sprite> hearts;

    //ParticleSystem ParticleSystem;
    //ParticleSystem ParticleSystem;
    sf::RectangleShape box;
    sf::Sprite spikes;
    sf::Texture spikeTexture;
    sf::Texture playerTexture;



};


#endif //GAME_ARENA_H
