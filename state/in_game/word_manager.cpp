#include "word_manager.h"

#include <fstream>
#include <SFML/Graphics/RenderTarget.hpp>

WorldManager::WorldManager() :
        currentWorld(0){
    loadWorldFileNames();
    loadWorld();
}

WorldManager::~WorldManager()
{
    //dtor
}

void WorldManager::update(int ticks){
    worlds[currentWorld].update(ticks);

    if (worlds[currentWorld].getStart().lock()->isCollided())
    {
        currentWorld = mWorlds[mCurrentWorld].getBlackHole().lock()->getNextWorld();
        loadWorld();
    }
}

void WorldManager::draw(sf::RenderTarget& target, float alpha){
    mWorlds[mCurrentWorld].draw(target, alpha);
}

void WorldManager::handleEvents(sf::Event& event){
    mWorlds[mCurrentWorld].handleEvents(event);
}

void WorldManager::loadWorld(){
    World world(mWorldFileNames[mCurrentWorld]);
    mWorlds.push_back(world);
}

void WorldManager::loadWorldFileNames(){

    std::string line = "";
    std::ifstream file("Content/Worlds/world_filenames.txt");

    if (file.is_open()){
        while (std::getline(file, line))
        {
            mWorldFileNames.push_back(line);
        }
    }

    file.close();
}