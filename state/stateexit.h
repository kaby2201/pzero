#ifndef STATEEXIT_H
#define STATEEXIT_H

#include "state.h"

class StateExit : public State {
public:
    StateExit(){
        goNext();
    };

    void enter();

    void render(sf::RenderWindow &window, float deltaTime);

    void goNext(Machine &machine) override;
    void handleEvents(sf::Event &event);
};
#endif