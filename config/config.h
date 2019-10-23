#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "engine/resource_manager.h"

class Config{
public:
    // This class can not be instantiated so all the methods will be static
    Config() = delete;

    Config(const Config &) = delete;

    Config &operator=(const Config &) = delete;

    // Screen dimensions
    const static unsigned int SCREEN_SCALE = 2; // '2' = 1280x720, '3' = 1920x1080
    const static unsigned int SCREEN_WIDTH = 640 * SCREEN_SCALE;
    const static unsigned int SCREEN_HEIGHT = 500 * SCREEN_SCALE;

    // Add all the texture here
    enum Textures : int{
        MENU_BACKGROUND,
        CURSOR
    };
    static ResourceManager<sf::Texture, int> textures;

    enum Sounds : int{
        MENU_SELECTION,
        ON_CLICK
    };
    static ResourceManager<sf::SoundBuffer, int> sounds;

    enum Fonts : int{
        MAIN_FONT
    };
    static ResourceManager<sf::Font, int> fonts;

    // Initializer all the resources
    static void init();

private:
    static void initTextures();
    static void initFonts();
    static void initConfig();
};


#endif
