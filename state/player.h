//
// Created by ALI on 08/11/2019.
//
#ifndef PZERO_PLAYER_H
#define PZERO_PLAYER_H

#include "SFML\Graphics.hpp"
#include "animation.h"

class player {
public:
    player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    animation animation;
    int row;
    float speed;
    bool faceRight;
    bool standStill;
};

#endif //PZERO_PLAYER_H
