#ifndef PZERO_SPRITE_INFO_H
#define PZERO_SPRITE_INFO_H


#include <SFML/Graphics.hpp>

struct SpriteInfo
{
    SpriteInfo() {}
    SpriteInfo(std::string path, int frames=1, int framesPerRow=1) :
            frames(frames),
            framesPerRow(framesPerRow)
    {
        texture.loadFromFile(path);
        frameDim = sf::Vector2f(texture.getSize().x/framesPerRow, texture.getSize().y/(frames/framesPerRow));
        hitBox = sf::FloatRect(0.f, 0.f, frameDim.x, frameDim.y);
    }

    sf::Texture texture;
    int frames;
    int framesPerRow;
    sf::Vector2f frameDim;
    sf::FloatRect hitBox;
};


#endif //PZERO_SPRITE_INFO_H
