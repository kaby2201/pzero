
#ifndef PZERO_MONSTER_H
#define PZERO_MONSTER_H

#include <SFML/Graphics.hpp>
#include <state/animation.h>
#include <state/collider.h>


class Monster {
public:
    Monster(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::View viewer(){ return view;};

    int getScore(){return  row;}
    bool finished = false;

    sf::Vector2f getPositions() { return body.getPosition();}
    Collider getCollider(){ return Collider(body); }

private:
    int monsterSwitch;
    sf::RectangleShape body;
    sf::View view;
    animation animation;
    int row;
    float speed;
    bool turnRight;
    bool faceRight;
    bool standStill;
};

#endif //PZERO_MONSTER_H
