#ifndef STATE_H
#define STATE_H

class Machine;

class State
{
public:
    State() {}
    virtual ~State() {};
    virtual void goNext(Machine &context) = 0;
};

#endif