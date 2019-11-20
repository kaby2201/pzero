#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "state/in_game/include/SpriteObject.h"
#include "state/in_game/include/ICollideable.h"

class Player : public SpriteObject, public ICollideable
{
    public:
        Player(SpriteInfo& info, sf::Vector2f pos);
        ~Player();

        bool onContactBegin(std::weak_ptr<ICollideable> object, bool fromLeft, bool fromTop);

        void update();
        void draw(sf::RenderTarget& target, float alpha);
        void handleEvents(sf::Event& event);

        void respawn(sf::Vector2f pos);

    private:
        int mRunSpeed;
        int mJumpSpeed;
        bool mGrounded;
        std::size_t mDirection;
};

#endif // PLAYER_H
