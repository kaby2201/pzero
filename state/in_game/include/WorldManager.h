#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <vector>
#include "World.h"

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

        std::size_t mCurrentWorld;
        std::vector<World> mWorlds;
        std::vector<std::string> mWorldFileNames;
};

#endif // WORLDMANAGER_H
