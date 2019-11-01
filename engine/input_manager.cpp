#include "input_manager.h"

bool InputManager::isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(button)) {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,object.getGlobalBounds().height);

        return tempRect.contains(sf::Mouse::getPosition(window));
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window) {
    return sf::Mouse::getPosition(window);
}

bool InputManager::isTextClicked(const sf::Text &obj, sf::Mouse::Button button, sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(button)) {
        sf::IntRect tempRect(obj.getPosition().x, obj.getPosition().y, obj.getGlobalBounds().width,
                             obj.getGlobalBounds().height);

        return tempRect.contains(sf::Mouse::getPosition(window));
    }
    return false;
}
