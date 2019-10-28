#include <iostream>
#include "config/config.h"
#include "state_main_manu.h"
#include "SFML/Graphics.hpp"

void StateMainMenu::goNext(Machine &machine) {
    std::cout << "Main menu" << std::endl;
}

StateMainMenu::StateMainMenu() {
    this->font = Config::fonts.get(Config::Fonts::MAIN_FONT);
    sf::Text text;
    text.setString("Main menu");

}