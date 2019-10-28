#ifndef STATE_MAIN_MANU_H
#define STATE_MAIN_MANU_H

#include "state.h"

class StateMainMenu : public State
{
public:
    StateMainMenu();
    void goNext(Machine &machine);
protected:
    sf::Texture gameTitle;
    sf::Font font;
};


#endif
