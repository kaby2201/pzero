#include "machine.h"
#include "state/stateexit.h"
#include "state/state_main_manu.h"

Machine::Machine(){
    // Start the machine running
    running = true;

    // Start in the main menu state
    state = StateId::STATE_MAIN_MENU;

    // Add states to the state map
    states.emplace(StateId::STATE_MAIN_MENU, new StateMainMenu());
    states.emplace(StateId::STATE_EXIT, new StateExit());
}

Machine::~Machine(){
    // Free the states from memory
    for (auto state: states) {
        delete state.second;
    }
    states.clear();
}

void Machine::goNext(){
    states[state]->goNext(*this);
}

void Machine::SetState(StateId state){
    this->state = state;
}