#ifndef PZERO_PLATFORM_H
#define PZERO_PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void draw(sf::RenderWindow &window);


private:
    sf::RectangleShape body;
};


#endif //PZERO_PLATFORM_H
