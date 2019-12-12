#ifndef PZERO_PLATFORM_H
#define PZERO_PLATFORM_H

#include <SFML/Graphics.hpp>
#include "collider.h"

class Platform {
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void draw(sf::RenderWindow &window);

    Collider getColider(){ return Collider(body); }

private:
    sf::RectangleShape body;
};


#endif //PZERO_PLATFORM_H
