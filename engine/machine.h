#ifndef MACHINE_H
#define MACHINE_H

#include <stack>
#include <memory>
#include "state/state.h"

typedef std::unique_ptr<State> stateRef;

class Machine {
public:
    Machine();
    ~Machine(){}

    void removeState();

    void processStateChanges();

    stateRef& getActiveState();

    void addState(stateRef newState, bool isReplacing = true);

private:
    std::stack<stateRef> states;
    stateRef newState;

    bool isRemoving;
    bool resuming;
    bool isAdding;
    bool isReplacing;
};


#endif //MACHINE_H
