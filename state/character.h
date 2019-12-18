#ifndef PZERO_CHARACTER_H
#define PZERO_CHARACTER_H

#include <SFML\Graphics.hpp>
#include "animation.h"
#include "collider.h"

class Character {
public:
    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, int speed, float jumpHeight);

    void Update(float deltaTime, sf::Vector2f& velocity);
    void draw(sf::RenderWindow& window);

    void setPosition(sf::Vector2f pos){ body.setPosition(pos); }

    void onCollision(sf::Vector2f& direction, sf::Vector2f& velocity);

    sf::Vector2f getPositions() { return body.getPosition();}
    Collider getCollider(){ return Collider(body); }

private:
    sf::Texture playerTexture;
    sf::RectangleShape body;
    sf::Vector2u imageCount;

    float switchTime = 0.03f;
    const float gravity = 2;
    unsigned int row;
    int speed = 5;
    bool faceRight;
    bool standStill;
    animation animation;

    //sf::Vector2f velocity;
    bool canJum = true;
    float jumHeight;
    float jumpSpeed = 9.0f;
};

#endif //PZERO_CHARACTER_H
