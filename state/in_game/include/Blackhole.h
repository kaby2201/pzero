#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "SpriteObject.h"
#include "ICollideable.h"

class Blackhole : public SpriteObject, public ICollideable
{
    public:
        Blackhole(SpriteInfo& info, sf::Vector2f pos, std::size_t nextWorld);
        ~Blackhole();

        bool onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);

        void setNextWorld(std::size_t nextWorld){mNextWorld=nextWorld;}

        std::size_t getNextWorld(){return mNextWorld;}
        bool isCollided(){return mCollided;}

    private:
        std::size_t mNextWorld; // the world that this wormhole leads to
        bool mCollided;
};

#endif // BLACKHOLE_H
