//
// Created by ALI on 08/11/2019.
//

#include "player.h"
#include "SFML\Graphics.hpp"

player::player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime)                                                     //caller constructor for å slippe gitter/getter
{
    this->speed = speed;
    row = 2;
    faceRight = false;

    body.setSize(sf::Vector2f(65, 65));
    body.setPosition(100, 500);
    body.setTexture(texture);
}

void player::Update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {

        movement.x -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {

        movement.x += speed * deltaTime;

    }
    if(movement.x == 0.0f){
        //     row = 3;
        standStill = true;
    } else {
        standStill = false;
        row = 11;

        if(movement.x >= 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    animation.Update(row, deltaTime, faceRight, standStill);

    body.setTextureRect(animation.uvRect);
    body.move(movement);


}

void player::Draw(sf::RenderWindow& window) {
    window.draw(body);
}

