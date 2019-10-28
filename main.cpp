#include <iostream>
#include <engine/game.h>
int main() {
    Game game;
    if(!game.init())
    {
        std::cout << "Fail to load game items" << std::endl;
        return EXIT_FAILURE;
    }
    game.run();

    return EXIT_SUCCESS;
}