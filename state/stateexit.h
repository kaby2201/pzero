#ifndef STATEEXIT_H
#define STATEEXIT_H

#include "state.h"

class StateExit : public State {
public:
    void goNext(Machine &machine) override;
};
#endif