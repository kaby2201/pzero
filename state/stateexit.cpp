#include <iostream>
#include <engine/machine.h>
#include "stateexit.h"


void StateExit::goNext(Machine &machine){
    std::cout << "Exiting..." << std::endl;
    machine.setRunning(false);
}