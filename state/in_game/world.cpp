#include "world.h"
#include "assets.h"

World::World(std::string path) {
    player = std::make_shared<Player>(Assets::sprites["bluepeewee"], sf::Vector2f());
    collideables.push_back(player);

    gravity = sf::Vector2f(0.f, 10.f);
    spawnPoint = sf::Vector2f(0.f, 0.f);
    // left, top, with, height
    boundaries = sf::FloatRect(0.f, 0.f, 800.f, 600.f);

    bg = sf::Sprite(Assets::sprites["background"].texture);
    star = std::make_shared<Star>(Assets::sprites["star"], sf::Vector2f());

    loadWorld(path);
}

void World::update(int ticks) {
    removeDeadObjects(renderables);
    removeDeadObjects(collideables);

    player->update();
    if (!player->isAlive()) {
        player->respawn(spawnPoint);
        collideables.push_back(player);
    }

    for (auto &obj : collideables) {
        obj->update();
    }
}

void World::draw(sf::RenderTarget &target, float alpha) {

}

void World::handleEvents(sf::Event &event) {

}

bool World::checkCollision(std::weak_ptr<Icollideable> a, std::weak_ptr<Icollideable> b) {
    return false;
}

void World::resolveCollision(std::weak_ptr<Icollideable> a, std::weak_ptr<Icollideable> b) {

}

void World::loadWorld(std::string path) {

}

template<class T>
void World::removeDeadObjects(std::vector<T> &vector) {

}
