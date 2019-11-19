#ifndef PZERO_SPRITE_OBJECT_H
#define PZERO_SPRITE_OBJECT_H


#include "irenderable.h"
#include "sprite_info.h"

class SpriteObject : public IRenderable{
public:
    SpriteObject(SpriteInfo &info, sf::Vector2f pos, bool parallax = false);

    virtual ~SpriteObject();

    virtual void update();

    virtual void draw(sf::RenderTarget &target, float alpha);

    // Mutator
    void setRenderPosition(sf::Vector2f pos){renderPosition=pos;
        sprite.setPosition(pos);
    }

    void setFrameLoop(int start, int stop, bool loop = true);

    // Accessor
    SpriteInfo getSpriteInfo(){ return spriteInfo; }
    sf::Sprite& getSprite() { return sprite; }
    sf::Vector2f getRenderPosition(){ return renderPosition; }
    bool isParallaxable(){ return parallaxable; }


protected:
    SpriteInfo spriteInfo;
    sf::Sprite sprite;
    sf::Vector2f renderPosition;

    bool parallaxable; // is this obj ment to be parallaxed

    int currentFrame;
    sf::Clock animClock;
    float frameDelay;
    bool loopAnim;
    bool startFrame;
    int endFrame;
    int frameDir;
};


#endif //PZERO_SPRITE_OBJECT_H
