//
// Created by Nicolas on 11/2/2019.
//

#include <iostream>
#include "SFML/Graphics.hpp"


#ifndef PZERO_MENU_H
#define PZERO_MENU_H
#define MAX_NUMBER_OF_Items 3
class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
   // sf::Text menu[MAX_NUMBER_OF_ITEMS];
   sf::Text menu[3];
};

#endif //PZERO_MENU_H
