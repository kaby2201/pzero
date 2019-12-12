#include <SFML/Graphics.hpp>

#include "layer.h"
#include "map/map.h"

void Layer::draw(sf::RenderWindow& window)
{
    // Render each tile
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            unsigned int gid = tilemap[x + y * width];

            // Skip empty tiles
            if (gid == 0)
                continue;

            sf::Vector2f size = sf::Vector2f(map.getTileWidth(), map.getTileHeight());
            sf::Vector2f position = sf::Vector2f((float)(x * map.getTileWidth()), (float)(y * map.getTileHeight()));

            sf::Sprite sprite;

            // Set source texture and position
            sprite.setOrigin(size / 2.0f);
            map.setSpriteTextureFromGid(sprite, gid);
            sprite.setPosition(position);

            body.setSize(size);
            body.setOrigin(size / 2.0f);
            body.setPosition(position);
            //body.setFillColor(sf::Color::Blue);
            //window.draw(body);

            window.draw(sprite);
        }
    }
}