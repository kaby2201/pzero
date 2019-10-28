#include "machine.h"

Machine::Machine() {}

void Machine::addState(stateRef newState, bool isReplacing) {
    this->isAdding = true;
    this->isReplacing = isReplacing;
    this->newState = std::move(newState);
}

void Machine::removeState() {
    this->isRemoving = true;
}

void Machine::processStateChanges(){

    if (this->isRemoving && !this->states.empty()){
        this->states.pop();

        if (!this->states.empty()){
            this->states.top()->resume();
        }

        this->isRemoving = false;
    }

    if (this->isAdding){
        if (!this->states.empty()){
            if (this->isReplacing){
                this->states.pop();
            }else{
                this->states.top()->pause();
            }
        }

        this->states.push(std::move(this->newState));
        this->states.top()->init();
        this->isAdding = false;
    }
}

stateRef &Machine::getActiveState(){
    return this->states.top();
}