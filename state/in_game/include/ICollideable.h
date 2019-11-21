#ifndef ICOLLIDEABLE_H
#define ICOLLIDEABLE_H

#include <memory>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include "IObject.h"

class ICollideable : virtual public IObject{
public:
    ICollideable(sf::FloatRect hitbox, sf::Vector2f dim, sf::Vector2f pos = sf::Vector2f(), bool _static = false){
        mHitBox = hitbox;
        mDimensions = dim;
        mPhysicsPosition = pos;
        mStatic = _static;
        mCollisionActive = true;
    }

    virtual bool onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop){return true;}
    virtual void onContactEnd(std::weak_ptr<ICollideable> object){}

    // Mutators
    void setHitBox(sf::FloatRect hitbox){mHitBox=hitbox;}
    void setDimensions(sf::Vector2f dim){mDimensions=dim;}
    void setPhysicsPosition(sf::Vector2f pos){mPhysicsPosition=pos;}
    void setVelocity(sf::Vector2f vel){mVelocity = vel;}

    // Accessors
    sf::FloatRect getHitBox(){return mHitBox;}
    sf::Vector2f getDimensions(){return mDimensions;}
    sf::Vector2f& getPhysicsPosition(){return mPhysicsPosition;}
    sf::Vector2f getVelocity(){return mVelocity;}
    bool isCollisionActive(){return mCollisionActive;}
    bool isStatic(){return mStatic;}

protected:
    sf::FloatRect mHitBox;
    sf::Vector2f mDimensions;
    sf::Vector2f mPhysicsPosition;
    sf::Vector2f mOldPhysicsPosition;
    sf::Vector2f mVelocity;
    bool mCollisionActive;
    bool mStatic;
};

#endif // ICOLLIDEABLE_H
