#include "config.h"

ResourceManager<sf::Texture, int> Config::textures;
ResourceManager<sf::Font, int> Config::fonts;

bool Config::loadResources() {
    // TODO make error handler
    initTextures();
    initFonts();
    initSounds();
    return true;
}

void Config::initTextures() {
    textures.load(Textures::MENU_BACKGROUND, MENU_BACKGROUND_IMAGE);
}

void Config::initFonts() {
    fonts.load(Fonts::MAIN_FONT, "resources/font/IndieFlower-Regular.ttf");
}

void Config::initSounds() {
    //sounds.load(Sounds::BACKGROUND_MUSIC, BACKGROUND_MUSIC);
}
