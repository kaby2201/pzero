#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager(){}
    ~InputManager(){}

    bool isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window);

    sf::Vector2i getMousePosition(sf::RenderWindow &window);
};


#endif //INPUT_MANAGER_H
