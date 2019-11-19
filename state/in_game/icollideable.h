#ifndef PZERO_ICOLLIDEABLE_H
#define PZERO_ICOLLIDEABLE_H
#include <memory>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "iobject.h"

class Icollideable : virtual public IObject{
public:
    Icollideable(sf::FloatRect hitbox, sf::Vector2f dim, sf::Vector2f pos = sf::Vector2f(), bool _static = false)
    {
        hitBox = hitbox;
        dimensions = dim;
        physicsPosition = pos;
        _static = isStatic_;
        collisionActive = true;
    }

    virtual bool onContactBegin(std::weak_ptr<Icollideable> object, bool fromLeft, bool fromTop){return true;}
    virtual void onContactEnd(std::weak_ptr<Icollideable> object){}

    // Mutators
    void setHitBox(sf::FloatRect hitbox){hitBox=hitbox;}
    void setDimensions(sf::Vector2f dim){dimensions=dim;}
    void setPhysicsPosition(sf::Vector2f pos){physicsPosition=pos;}
    void setVelocity(sf::Vector2f vel){velocity = vel;}

    // Accessors
    sf::FloatRect getHitBox(){return hitBox;}
    sf::Vector2f getDimensions(){return dimensions;}
    sf::Vector2f& getPhysicsPosition(){return physicsPosition;}
    sf::Vector2f getVelocity(){return velocity;}
    bool isCollisionActive(){return collisionActive;}
    bool isStatic(){return isStatic_;}

protected:
    sf::FloatRect hitBox;
    sf::Vector2f dimensions;
    sf::Vector2f physicsPosition;
    sf::Vector2f oldPhysicsPosition;
    sf::Vector2f velocity;
    bool collisionActive;
    bool isStatic_;
};


#endif //PZERO_ICOLLIDEABLE_H
