#include "sprite_object.h"


SpriteObject::~SpriteObject() {

}

SpriteObject::SpriteObject(SpriteInfo &info, sf::Vector2f pos, bool parallax) : IRenderable {
        spriteInfo(info),
        parallaxable(parallax),
        currentFrame(0), frameDelay(100.f), loopAnim(true), startFrame(0), endFrame(0), frameDir(1){
            mSprite = sf::Sprite(info.mTexture);
            mRenderPosition = pos;
}
