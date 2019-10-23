#include <engine/machine.h>

int main() {
    // Create the machine
    Machine machine;

    // Run until the running flag is set to false
    while (machine.GetRunning())
        machine.goNext();

    return EXIT_SUCCESS;
}