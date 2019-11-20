#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include <SFML/Graphics.hpp>

#include "state/in_game/include/IRenderable.h"
#include "SpriteInfo.h"

class SpriteObject : public IRenderable{
    public:
        SpriteObject(SpriteInfo& info, sf::Vector2f pos, bool parallax=false);
        virtual ~SpriteObject();

        virtual void update();
        virtual void draw(sf::RenderTarget& target, float alpha);

        // Mutator
        void setRenderPosition(sf::Vector2f pos){mRenderPosition=pos; mSprite.setPosition(pos);}
        void setFrameLoop(int start, int stop, bool loop=true);

        // Accessor
        SpriteInfo getSpriteInfo(){return mSpriteInfo;}
        sf::Sprite& getSprite(){return mSprite;}
        sf::Vector2f getRenderPosition(){return mRenderPosition;}
        bool isParallaxable(){return mParallaxable;}

    protected:
        SpriteInfo& mSpriteInfo;
        sf::Sprite mSprite;
        sf::Vector2f mRenderPosition;

        bool mParallaxable; // is this object meant to be parallaxed

        int mCurrentFrame;
        sf::Clock mAnimClock;
        float mFrameDelay;
        bool mLoopAnim;
        int mStartFrame;
        int mEndFrame;
        int mFrameDir;
};

#endif // SPRITEOBJECT_H
