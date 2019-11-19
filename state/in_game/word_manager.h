#ifndef WORD_MANAGER_H
#define WORD_MANAGER_H

#include <vector>
#include "world.h"

class WorldManager{
public:
    WorldManager();
    ~WorldManager();

    void update(int ticks);
    void draw(sf::RenderTarget& target, float alpha);
    void handleEvents(sf::Event& event);

private:
    void loadWorld();
    void loadWorldFileNames();

    std::size_t currentWorld;
    std::vector<World> worlds;
    std::vector<std::string> worldFileNames;
};


#endif //WORD_MANAGER_H
