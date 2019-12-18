#include "monster.h"

Monster::Monster(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime) //caller constructor for å slippe gitter/getter
{
    this->speed = speed;
    row = 2;
    faceRight = false;
    standStill = false;

    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(750, 355);
    body.setTexture(texture);
    monsterSwitch = 1;
}

void Monster::Update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movement.y -= speed * deltaTime;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movement.y += speed * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += speed * deltaTime;
    }
    if(body.getPosition().x > 3000){
        movement.x += speed * deltaTime;
    }

    if(body.getPosition().x >= 750 and body.getPosition().x <= 760){
       turnRight = true;
    } else if (body.getPosition().x > 900 and body.getPosition().x < 910){
        turnRight = false;
    }
    if(turnRight){
        movement.x += speed * deltaTime;
    } else if(!turnRight){
        movement.x -= speed * deltaTime;
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

void Monster::draw(sf::RenderWindow& window) {
    window.draw(body);
}


