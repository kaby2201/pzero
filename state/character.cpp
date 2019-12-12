#include <DEFINITIONS.hpp>
#include <math.h>
#include "character.h"

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
        animation(texture, imageCount, switchTime)
        //caller constructor for å slippe gitter/getter
{
    this->speed = speed;
    this->jumHeight = jumpHeight;
    row = 2;
    faceRight = false;
    standStill = false;
    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(SCREEN_WIDTH/4, SCREEN_HEIGHT/5);
    body.setTexture(texture);
}

void Character::Update(float deltaTime) {

    velocity.x *= 0.f; // TODO play around with this and see resultat

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJum) {
        canJum = false;
        velocity.y = -sqrtf(2.0f * 9.810f * jumHeight);
    }

    velocity.y += 981.0f * deltaTime;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity.x -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x += speed * deltaTime;
    }

    if(velocity.x == 0.0f){
        //     row = 3;
        standStill = true;
    } else {
        standStill = false;
        row = 11;

        faceRight = velocity.x >= 0;
    }

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);

}

void Character::onCollision(sf::Vector2f& direction) {
    if (direction.x < 0.0f) {
        // Collision on the left
        velocity.x = 0.0f;
    } else if (direction.x > 0.0f) {
        velocity.x = 0.0f;
    }

    if (direction.y < 0.0f) {
        // Collision on the bottom.
        velocity.y = 0.0f;
        canJum = true;
    } else if (direction.y > 0.0f) {
        // Collision on top
        velocity.y = 0.0f;
    }
}

