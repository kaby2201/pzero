//
// Created by ALI on 08/11/2019.
//
#ifndef PZERO_CHARACTER_H
#define PZERO_CHARACTER_H

#include "SFML\Graphics.hpp"
#include "animation.h"

class character {
public:
    character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);


    sf::Vector2f GetPositions() { return body.getPosition();}

private:
    sf::RectangleShape body;
    animation animation;
    int row;
    float speed;
    bool faceRight;
    bool standStill;

};

#endif //PZERO_CHARACTER_H
