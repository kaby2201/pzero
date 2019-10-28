#ifndef MACHINE_H
#define MACHINE_H

#include <map>

class State;

class Machine{
public:
    enum class StateId {
        STATE_NONE,
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
    void setState(StateId state);
    bool isRunning() const { return running; }
    void setRunning(bool running) { this->running = running; }

protected:
    bool running;
    static Machine* machine;
    StateId state;
    std::map<StateId, State*> states;
};

#endif
