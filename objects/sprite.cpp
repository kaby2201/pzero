#include <SFML/Graphics.hpp>

#include "sprite.h"
#include "map/map.h"

void Sprite::process(float deltaTime)
{
    auto& animation = map.getAnimation(gid);

    if (!animation)
        return;

    // Go to next animation frame if required
    if (clock.getElapsedTime().asMilliseconds() < (*animation)[frame].duration)
        return;

    if (++frame >= (int)animation->size())
        frame = 0;

    clock.restart();
}

void Sprite::draw(sf::RenderWindow& window)
{
    map.setSpriteTextureFromGid(sprite, gid, frame);

    //Get sprite size
    sf::Vector2f size = sf::Vector2f(width, height);
    sprite.setOrigin(size / 2.0f);
    sprite.setPosition((float)x, (float)y);


    body.setPosition((float) x, (float) y);
    body.setOrigin(size / 2.0f);
    window.draw(sprite);
    window.draw(body);
}