#include <DEFINITIONS.hpp>
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

    view.setSize(800, 600);
    view.setCenter(400, 250);
    body.setSize(sf::Vector2f(30.f, 30.f));
    body.setOrigin(body.getSize()/2.f);
    body.setPosition(100, 415);
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

    animation.Update(row, deltaTime, faceRight, standStill);
    body.setTextureRect(animation.uvRect);
    body.move(movement);

     if (body.getPosition().x > 400 and body.getPosition().x < 2800){
        view.setCenter(body.getPosition().x, 250);
    } else if(body.getPosition().x > 3500){
      finished = true;
     }

}

void Character::draw(sf::RenderWindow& window) {
    window.draw(body);


}






