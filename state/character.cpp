#include <DEFINITIONS.hpp>
#include <math.h>
#include <iostream>
#include "character.h"

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, int speed, float jumpHeight) :
        animation(texture, imageCount, switchTime)
//caller constructor for å slippe gitter/getter
{
    this->jumHeight = jumpHeight;
    this->speed = speed;
    row = 2;
    faceRight = false;
    standStill = false;
    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(100, 400);
    body.setTexture(texture);
}

void Character::Update(float deltaTime, sf::Vector2f& velocity) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = speed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -speed;
    }
    else{
        velocity.x = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y = -jumpSpeed;
    }

    if (body.getPosition().y + body.getSize().y < 35*16 || velocity.y < 0) {
        velocity.y +=gravity;
    } else {
        body.setPosition(body.getPosition().x, 35*16 - body.getSize().y);
        velocity.y = 3;
    }

    if(velocity.x == 0.0f){
        standStill = true;
    } else {
        standStill = false;
        row = 11;

        if (velocity.x >= 0.0f) {
            faceRight = true;
        }else{
            faceRight = false;
        }
    }

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(velocity.x, velocity.y);
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);
}

void Character::onCollision(sf::Vector2f& direction, sf::Vector2f& velocity) {

    // Collision on the left
    if (direction.x < 0.0f) {
        velocity.x = 0.0f;
    } else if (direction.x > 0.0f) {
        // Collision on the right
        velocity.x = 0.0f;
    }

    // Collision on the bottom
    if (direction.y < 0.0f) {
        velocity.y = 0.0f;
    } else if (direction.y > 0.0f) {
        // Collision on top
        velocity.y = 0.0f;
        canJum = false;
    }
}

