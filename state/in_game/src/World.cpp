#include "state/in_game/include/World.h"

#include <sstream>
#include <fstream>

#include "state/in_game/include/Assets.h"
#include "state/in_game/include/Constants.h"

World::World(std::string path)
{
    mPlayer = std::make_shared<Player>(Assets::sprites["bluepeewee"], sf::Vector2f());
    mCollideables.push_back(mPlayer);

    mGravity = sf::Vector2f(0.f, 10.f);
    mSpawnPoint = sf::Vector2f(0.f,  0.f);
    mBoundaries = sf::FloatRect(0.f,  0.f, 800.f, 600.f); // left, top, width, height

    mBackground = sf::Sprite(Assets::sprites["background"].mTexture);
    mBlackHole = std::make_shared<Blackhole>(Assets::sprites["blackhole"], sf::Vector2f(), 0);

    loadWorld(path);
}

World::~World()
{
    //dtor
}

void World::update(int ticks)
{
    removeDeadObjects(mRenderables);
    removeDeadObjects(mCollideables);

    mPlayer->update();
    if (!mPlayer->isAlive())
    {
        mPlayer->respawn(mSpawnPoint);
        mCollideables.push_back(mPlayer);
    }

    for (auto& obj : mCollideables){
        obj->update();
        if (!obj->isStatic())
            obj->setVelocity(obj->getVelocity() + mGravity*(UPDATE_STEP.asSeconds()));
        if (obj->getPhysicsPosition().y > SCREEN_HEIGHT)
            obj->kill();
    }

    for (auto& obj : mRenderables){
        if (obj->isParallaxable()){
            obj->setRenderPosition(obj->getRenderPosition() + sf::Vector2f(0.25f, 0.f));
            if (obj->getRenderPosition().x > SCREEN_WIDTH)
                obj->setRenderPosition(sf::Vector2f(-obj->getSpriteInfo().mHitBox.width, obj->getRenderPosition().y));
        }
    }

    // check collisions
    for (std::size_t x = 0; x < mCollideables.size(); x++)
    {
        for (std::size_t y = x+1; y < mCollideables.size(); y++)
        {
            auto dynamic = mCollideables[x];
            auto _static = mCollideables[y];

            if (!mCollideables[x]->isStatic())
                dynamic = mCollideables[x];
            else if (!mCollideables[y]->isStatic())
                dynamic = mCollideables[y];

            if (mCollideables[x]->isStatic())
                _static = mCollideables[x];
            else if (mCollideables[y]->isStatic())
                _static = mCollideables[y];

            if (dynamic != _static)
            {
                if (checkCollision(dynamic, _static) && dynamic->isCollisionActive() && _static->isCollisionActive())
                    resolveCollision(dynamic, _static);
            }
        }
    }

    mCamera.follow(sf::Vector2f(mPlayer->getRenderPosition().x, SCREEN_HEIGHT/2.f));
}

void World::draw(sf::RenderTarget& target, float alpha){
    target.setView(target.getDefaultView());

    target.draw(mBackground);

    for (auto& obj : mRenderables)
    {
        if (obj->isParallaxable())
        {
            obj->draw(target, alpha);
        }
    }

    target.setView(mCamera.getView());


    mPlayer->draw(target, alpha);

    auto windowCoords = sf::FloatRect(mCamera.getCenter().x-(SCREEN_WIDTH/2),
                                      mCamera.getCenter().y-(SCREEN_HEIGHT/2), SCREEN_WIDTH, SCREEN_HEIGHT);

    for (auto& obj : mRenderables){
        if (windowCoords.intersects(obj->getSprite().getGlobalBounds()) && !obj->isParallaxable()){
            obj->draw(target, alpha);
        }
    }
}

void World::handleEvents(sf::Event& event)
{
    mPlayer->handleEvents(event);
}

void World::loadWorld(std::string path)
{
    // basic file loading stuff
    std::string line = "";
    std::ifstream file(path);

    auto findKey = [](std::string key, std::string line) -> bool
    {
        std::size_t pos = 0;
        pos = line.find(key);
        if (pos != std::string::npos)
            return true;

        return false;
    };

    auto splitStringBySpaces = [](std::string line) -> std::vector<std::string>
    {
        std::istringstream iss(line);
        std::vector<std::string> split_array;
        while (iss)
        {
            std::string sub;
            iss >> sub;
            split_array.push_back(sub);
        }

        return split_array;
    };

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            auto split_line = splitStringBySpaces(line);
            if (findKey("spawnpoint:", line))
            {
                float x = std::stof(split_line[1]);
                float y = std::stof(split_line[2]);

                mSpawnPoint = sf::Vector2f(x, y);
                mPlayer->setPhysicsPosition(mSpawnPoint);
            }
            else if (findKey("boundaries:", line))
            {
                float x = std::stof(split_line[1]);
                float y = std::stof(split_line[2]);
                float width = std::stof(split_line[3]);
                float height = std::stof(split_line[4]);

                mBoundaries = sf::FloatRect(x, y, width, height);
            }
            else if (findKey("blackhole:", line))
            {
                float x = std::stof(split_line[1]);
                float y = std::stof(split_line[2]);
                std::size_t nextWorld = std::stof(split_line[3]);

                mBlackHole->setPhysicsPosition(sf::Vector2f(x, y));
                mBlackHole->setRenderPosition(sf::Vector2f(x, y));
                mBlackHole->setNextWorld(nextWorld);
                mRenderables.push_back(mBlackHole);
                mCollideables.push_back(mBlackHole);
            }
            else if (findKey("platform:", line))
            {
                std::string id = split_line[1];
                float x = std::stof(split_line[2]);
                float y = std::stof(split_line[3]);

                auto platform = std::make_shared<WorldObject>(Assets::sprites[id], sf::Vector2f(x, y), true);
                mRenderables.push_back(platform);
                mCollideables.push_back(platform);
            }
            else if (findKey("renderonly:", line))
            {
                std::string id = split_line[1];
                float x = std::stof(split_line[2]);
                float y = std::stof(split_line[3]);
                bool parallax = false;

                if (split_line[4] == "parallax")
                    parallax = true;

                auto obj = std::make_shared<SpriteObject>(Assets::sprites[id], sf::Vector2f(x, y), parallax);
                mRenderables.push_back(obj);
            }
        }
    }
}

bool World::checkCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b){
    sf::Vector2f a1 = a.lock()->getPhysicsPosition() + sf::Vector2f(a.lock()->getHitBox().left, a.lock()->getHitBox().top);
    sf::Vector2f a2 = sf::Vector2f(a.lock()->getHitBox().width, a.lock()->getHitBox().height);

    sf::Vector2f b1 = b.lock()->getPhysicsPosition() + sf::Vector2f(b.lock()->getHitBox().left, b.lock()->getHitBox().top);
    sf::Vector2f b2 = sf::Vector2f(b.lock()->getHitBox().width, b.lock()->getHitBox().height);

    //float rect = (left, top, width, height)
    sf::FloatRect aRect(a1, a2);
    sf::FloatRect bRect(b1, b2);

    if (aRect.intersects(bRect))
        return true;

    return false;
}

void World::resolveCollision(std::weak_ptr<ICollideable> a, std::weak_ptr<ICollideable> b)
{
    auto aLeft = a.lock()->getPhysicsPosition().x + a.lock()->getHitBox().left;
    auto aTop = a.lock()->getPhysicsPosition().y + a.lock()->getHitBox().top;
    auto aRight = aLeft + a.lock()->getHitBox().width;
    auto aBottom = aTop + a.lock()->getHitBox().height;

    auto bLeft = b.lock()->getPhysicsPosition().x + b.lock()->getHitBox().left;
    auto bTop = b.lock()->getPhysicsPosition().y + b.lock()->getHitBox().top;
    auto bRight = bLeft + b.lock()->getHitBox().width;
    auto bBottom = bTop + b.lock()->getHitBox().height;

    float overlapLeft {aRight - bLeft};
    float overlapRight {bRight - aLeft};
    float overlapTop {aBottom - bTop};
    float overlapBottom {bBottom - aTop};

    bool fromLeft(std::abs(overlapLeft) < std::abs(overlapRight));
    bool fromTop(std::abs(overlapTop) < std::abs(overlapBottom));

    float minOverlapX {fromLeft ? overlapLeft : overlapRight};
    float minOverlapY {fromTop ? overlapTop : overlapBottom};

    auto y_collision = [a, fromTop](float overlapX, float overlapY, bool stair=false)
    {
        if (fromTop)
        {
            if (stair)
            {
                a.lock()->setVelocity(sf::Vector2f(a.lock()->getVelocity().x, 0.f));
                a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x-5.f, a.lock()->getPhysicsPosition().y - overlapY));
            }
            else
            {
                a.lock()->setVelocity(sf::Vector2f(a.lock()->getVelocity().x, 0.f));
                a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x, a.lock()->getPhysicsPosition().y - overlapY));
            }
        }
        else if (!fromTop)
        {
            a.lock()->setVelocity(sf::Vector2f(a.lock()->getVelocity().x, 0.f));
            a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x, a.lock()->getPhysicsPosition().y + overlapY));
        }
    };

    auto x_collision = [a, fromLeft, fromTop, y_collision](float overlapX, float overlapY)
    {
        if (overlapY < 20.f && fromTop) // it's probably a stair
        {
            y_collision(overlapX, overlapY, true);
            return;
        }

        a.lock()->setVelocity(sf::Vector2f(0.f, a.lock()->getVelocity().y));

        if (fromLeft)
        {
            a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x - overlapX, a.lock()->getPhysicsPosition().y));
        }
        else if (!fromLeft)
        {
            a.lock()->setPhysicsPosition(sf::Vector2f(a.lock()->getPhysicsPosition().x + overlapX, a.lock()->getPhysicsPosition().y));
        }
    };

    if (a.lock()->onContactBegin(b, fromLeft, fromTop) && b.lock()->onContactBegin(a, fromLeft, fromTop))
    {
        if (std::abs(minOverlapX) > std::abs(minOverlapY)) // y overlap
        {
            y_collision(minOverlapX, minOverlapY);
        }
        else if (std::abs(minOverlapX) < std::abs(minOverlapY)) // x overlap
        {
            x_collision(minOverlapX, minOverlapY);
        }

        a.lock()->onContactEnd(b);
        b.lock()->onContactEnd(a);
    }
}

template <class T>
void World::removeDeadObjects(std::vector<T>& v)
{
    typename std::vector<T>::iterator it;

    for (it = v.begin(); it != v.end();)
    {
        if(!(*it)->isAlive())
        {
            it = v.erase(it);
        }
        else
        {
            it++;
        }
    }
}
