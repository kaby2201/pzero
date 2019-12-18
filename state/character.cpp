#include <DEFINITIONS.hpp>
#include <iostream>
#include "character.h"
#include "game_over_state.h"

Character::Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime)                                                     //caller constructor for å slippe gitter/getter
{
    this->speed = speed;
    row = 2;
    faceRight = false;
    standStill = false;

    //800, 600
    //0.4166, 0.555
    view.setSize(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    view.setCenter(480, 300);
    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(100, 485);
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
    if(body.getPosition().x > 3000){
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
    if(body.getPosition().x <1000 and body.getPosition().x >1200){
        body.setSize(sf::Vector2f(60.f, 60.f));
    } else  body.setSize(sf::Vector2f(30.f, 30.f));

    if (body.getPosition().x > 480 and body.getPosition().x < 2720){
        view.setCenter(body.getPosition().x, 300);
    } else if(body.getPosition().x > 3500){
        finished = !finished;
    }

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(movement);





}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);


}






