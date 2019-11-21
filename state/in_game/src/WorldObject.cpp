#include "state/in_game/include/WorldObject.h"

WorldObject::WorldObject(SpriteInfo& info, sf::Vector2f pos, bool _static) :
    SpriteObject(info, pos),
    ICollideable(info.mHitBox, info.mFrameDim, pos, _static)
{
    //ctor
}

WorldObject::~WorldObject(){

}

void WorldObject::update(){
    SpriteObject::update();

    mOldPhysicsPosition = mPhysicsPosition;
    mPhysicsPosition += mVelocity;
}

void WorldObject::draw(sf::RenderTarget& target, float alpha){
    SpriteObject::draw(target, alpha);

    mRenderPosition = mPhysicsPosition*alpha + mOldPhysicsPosition*(1.f - alpha);
}
