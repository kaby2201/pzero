#ifndef PZERO_CHARACTER_H
#define PZERO_CHARACTER_H

#include <SFML\Graphics.hpp>
#include "animation.h"
#include "game.h"


class Character {
public:
    Character(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::View viewer(){ return view;};
    int getScore(){
        return  row;
    }
    bool finished = false;

private:
    sf::RectangleShape body;
    sf::View view;
    animation animation;
    int row;
    float speed;
    bool faceRight;
    bool standStill;


};

#endif //PZERO_CHARACTER_H
