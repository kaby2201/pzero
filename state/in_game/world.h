#ifndef PZERO_WORLD_H
#define PZERO_WORLD_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "camera.h"
#include "star.h"
#include "icollideable.h"
#include "player.h"
#include "sprite_object.h"

class World {
public:
    World(std::string path);
    ~World(){}

    void update(int ticks);

    void draw(sf::RenderTarget &target, float alpha);

    void handleEvents(sf::Event &event);

    std::weak_ptr<Star> getStart(){ return this->star;}

private:
    bool checkCollision(std::weak_ptr<Icollideable> a, std::weak_ptr<Icollideable> b);

    void resolveCollision(std::weak_ptr<Icollideable> a, std::weak_ptr<Icollideable> b);

    void loadWorld(std::string path);

    template<class T>
    void removeDeadObjects(std::vector<T> &vector);

    sf::Vector2f gravity;
    sf::Vector2f spawnPoint;
    sf::FloatRect boundaries;

    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<SpriteObject>> renderables;
    std::vector<std::shared_ptr<Icollideable>> collideables;

    sf::Sprite bg;
    std::shared_ptr<Star> star; //share_ptr so it can be added to reanderable and collideable

    Camera camera;

};


#endif //PZERO_WORLD_H
