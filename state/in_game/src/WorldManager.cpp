#include "state/in_game/include/WorldManager.h"

#include <fstream>

WorldManager::WorldManager() :
    mCurrentWorld(0){
    loadWorldFileNames();
    loadWorld();
}

WorldManager::~WorldManager(){
    //dtor
}

void WorldManager::update(int ticks){
    mWorlds[mCurrentWorld].update(ticks);

    if (mWorlds[mCurrentWorld].getBlackHole().lock()->isCollided())
    {
        mCurrentWorld = mWorlds[mCurrentWorld].getBlackHole().lock()->getNextWorld();
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
    std::ifstream file("resources/map/map_filenames.txt");

    if (file.is_open()){
        while (std::getline(file, line))
        {
            mWorldFileNames.push_back(line);
        }
    }

    file.close();
}
