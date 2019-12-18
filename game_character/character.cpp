#include <DEFINITIONS.hpp>
#include "character.h"
#include <cmath>
#include <iostream>

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
        animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 2;

    faceRight = false;
    standStill = false;

    view.setSize(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    view.setCenter(480, 300);

    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(100, 400);
    body.setTexture(texture);
}

void Character::Update(float deltaTime) {
    int groundHeight = 560;
    float gravity = 1;
    /*if(velocity.y >= 0)
        canJum = true;*/

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = moveSpeed;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -moveSpeed;
    }
    else{
        velocity.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJum) {
        velocity.y = -jumpSpeed;
        canJum = false;
    }

    if (body.getPosition().y + body.getSize().y < groundHeight  || velocity.y < 0) {
            velocity.y +=gravity;
            canJum = false;
    } else{
        body.setPosition(body.getPosition().x, groundHeight - body.getSize().y);
        velocity.y = 0;
        canJum = true;
    }


    if(velocity.x == 0.0f){
        //     row = 3;
        standStill = true;
    } else {
        standStill = false;
        row = 11;

        faceRight = velocity.x >= 0;
    }


    if(body.getPosition().x < 1000 and body.getPosition().x > 1200){
        body.setSize(sf::Vector2f(60.f, 60.f));
    } else  body.setSize(sf::Vector2f(30.f, 30.f));

    if (body.getPosition().x > 480 and body.getPosition().x < 2720){
        view.setCenter(body.getPosition().x, 300);
    } else if(body.getPosition().x > 3200){
        finished = true;
    }

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(velocity.x, velocity.y);
    std::cout << velocity.y << std::endl;
}

void Character::onCollision(sf::Vector2f& direction) {

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
        canJum = true;

    } else if (direction.y > 0.0f) {
        // Collision on top
        velocity.y = 0;
    }

    if(finished) {
        direction.y = 3;
    }
}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);
}
