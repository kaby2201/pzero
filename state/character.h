#ifndef PZERO_CHARACTER_H
#define PZERO_CHARACTER_H

#include <SFML\Graphics.hpp>
#include "animation.h"
#include "collider.h"

class Character {
public:
    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);

    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void onCollision(sf::Vector2f& direction);

    sf::Vector2f GetPositions() { return body.getPosition();}
    Collider getCollider(){ return Collider(body); }

private:
    sf::RectangleShape body;
    animation animation;
    int row;
    float speed;
    bool faceRight;
    bool standStill;

    sf::Vector2f velocity;
    bool canJum = false;
    float jumHeight;
};

#endif //PZERO_CHARACTER_H
