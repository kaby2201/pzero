#ifndef MACHINE_H
#define MACHINE_H

#include <map>

class State;

class Machine
{
public:
    enum class StateId { HELLO, GOODBYE, EXIT,
        STATE_MAIN_MENU,
        STATE_OPTION_MENU,
        STATE_HIGH_SCORE,
        STATE_GAME_SETTINGS,
        STATE_EXIT,
        STATE_PAUSE_MENU
    };

    Machine();
    ~Machine();

    void goNext();
    void SetState(StateId state);
    bool GetRunning() const { return running; }
    void SetRunning(bool running) { this->running = running; }

protected:
    bool running;
    StateId state;
    std::map<StateId, State*> states;
};

#endif
