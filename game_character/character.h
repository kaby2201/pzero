#ifndef PZERO_CHARACTER_H
#define PZERO_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "state/animation.h"
#include "state/collider.h"
#include "state/game.h"

class Character {
public:
    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);

    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void setPosition(sf::Vector2f pos){ body.setPosition(pos); }

    void onCollision(sf::Vector2f& direction);

    sf::Vector2f getPositions() { return body.getPosition();}
    Collider getCollider(){ return Collider(body); }

    sf::View viewer(){ return view;};


    bool finished = false;
private:
    sf::RectangleShape body;
    unsigned int row;

    sf::View view;

    bool isAlive = true;
    animation animation;
    bool faceRight;
    bool standStill;

    // Motion
    sf::Vector2f velocity;
    bool canJum;
    float jumpHeight;
    float speed;
    bool grounded = false;
    float moveSpeed = 8.0f, jumpSpeed = 9.0f;
};

#endif //PZERO_CHARACTER_H
