#include "state/in_game/include/SpriteObject.h"

SpriteObject::SpriteObject(SpriteInfo& info, sf::Vector2f pos, bool parallax) : IRenderable(),
    mSpriteInfo(info),
    mParallaxable(parallax),
    mCurrentFrame(0), mFrameDelay(100.f), mLoopAnim(true), mStartFrame(0), mEndFrame(0), mFrameDir(1)
{
    mSprite = sf::Sprite(info.mTexture);
    mRenderPosition = pos;
}

SpriteObject::~SpriteObject(){
    //dtor
}

void SpriteObject::update(){
    mSprite.setPosition(mRenderPosition);
}

void SpriteObject::draw(sf::RenderTarget& target, float alpha)
{
    if (mAnimClock.getElapsedTime().asMilliseconds() >= mFrameDelay &&
            (mLoopAnim || (mFrameDir == 1 && mCurrentFrame != mEndFrame) || (mFrameDir == -1 && mCurrentFrame != mStartFrame)))
    {
        mAnimClock.restart();
        mCurrentFrame += mFrameDir;

        if (mCurrentFrame > mEndFrame && mFrameDir == 1 && mLoopAnim)
            mCurrentFrame = mStartFrame;
        else if (mCurrentFrame < mStartFrame && mFrameDir == -1 && mLoopAnim)
            mCurrentFrame = mEndFrame;
    }

    // Calculate frame position
    if (mSpriteInfo.mFramesPerRow > 1)
    {
        int frameX = (mCurrentFrame%mSpriteInfo.mFramesPerRow)*mSpriteInfo.mFrameDim.x;
        int frameY = (mCurrentFrame/mSpriteInfo.mFramesPerRow)*mSpriteInfo.mFrameDim.y;
        mSprite.setTextureRect(sf::IntRect(frameX, frameY, mSpriteInfo.mFrameDim.x, mSpriteInfo.mFrameDim.y));
    }

    target.draw(mSprite);
}

void SpriteObject::setFrameLoop(int start, int stop, bool loop){
    mLoopAnim = loop;

    if (start == mStartFrame && stop == mEndFrame)
        return;

    if (start <= stop){
        mStartFrame = start;
        mEndFrame = stop;
        mCurrentFrame = start;
        mFrameDir = 1;
    }
    else{
        mStartFrame = stop;
        mEndFrame = start;
        mCurrentFrame = start;
        mFrameDir = -1;
    }
}
