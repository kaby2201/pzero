#ifndef PZERO_PLAYER_H
#define PZERO_PLAYER_H


#include <memory>
#include "sprite_object.h"
#include "icollideable.h"
#include "sprite_info.h"

class Player : public SpriteObject, public Icollideable{
public:
    Player(SpriteInfo &info, sf::Vector2f pos);

    ~Player();

    bool onContactBegin(std::weak_ptr<Icollideable> object, bool fromLeft, bool fromTop);

    void update();

    void draw(sf::RenderTarget &target, float alpha);

    void handleEvent(sf::Event &event);

    void respawn(sf::Vector2f post);

private:
    int runSpeed;
    int jumSpeed;
    bool grounded;
    std::size_t  direction;

};


#endif //PZERO_PLAYER_H
