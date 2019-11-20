#include <state/in_game/include/Blackhole.h>


Blackhole::Blackhole(SpriteInfo& info, sf::Vector2f pos, std::size_t nextWorld) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos),
    mNextWorld(nextWorld),
    mCollided(false)
{
    //ctor
}

Blackhole::~Blackhole()
{
    //dtor
}

bool Blackhole::onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop)
{
    mCollided = true;
    return false;
}
