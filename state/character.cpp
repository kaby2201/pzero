#include "character.h"

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime)                                                     //caller constructor for å slippe gitter/getter
{
    this->speed = speed;
    row = 2;
    faceRight = false;
    standStill = false;

    body.setSize(sf::Vector2f(65.f, 65.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(250.f, 750.f);
    body.setTexture(texture);
}

void Character::Update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        movement.y -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        movement.y += speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        movement.x += speed * deltaTime;
    }

    if(movement.x == 0.0f){
        //     row = 3;
        standStill = true;
    } else {
        standStill = false;
        row = 11;

        faceRight = movement.x >= 0;
    }

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);
}

