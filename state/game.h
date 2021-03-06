#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <engine/machine.h>
#include <engine/asset_manager.h>
#include <engine/input_manager.h>
#include <SFML/Audio/Sound.hpp>
#include "game_character/character.h"


/*
 *  Add all game asset resources here. If you know whey will be used two
 */

enum class Texture : int {
    WELCOME_BACKGROUND_IMG,
    BACKGROUND_CLOUD_TEXTURE,
    TABLE_BACKGROUND_TEXTURE,
    OFF_MUTE,
    ON_MUTE,
    VOLUME_INCREASE,
    DECREASE_VOLUME,
    EXIT,
    TABLE,
    BUTTON_PLAY,
    BUTTON_SETTING,
    BUTTON_HELP,
    BUTTON_SCORE,
    MENU_BOARD_BACKGROUND,
    BUTTON_EXIT,
    PAUSE_HEADER,
    SPACEBAR,
    LEFT_POINTER,
    RIGHT_POINTER,
    COIN,
    HEART
};

enum class Font : int {
    GAME_TITLE,
    MAIN_FONT
};



enum class Music : int {
    BACKGROUND_MUSIC
};

struct GameData {
    Machine machine;
    InputManager input;
    sf::RenderWindow window;
    sf::Sound sound;
    AssetManager<sf::Font, Font> fonts;

    AssetManager<sf::SoundBuffer, Music> music;
    AssetManager<sf::Sprite, int> sprites;
    AssetManager<sf::Texture, Texture> textures;

    // Player is alive
    bool isAlive = true;
};

typedef std::shared_ptr<GameData> gameDataRef;

class Game {
public:
    Game(int width, int height, const std::string &title);

private:
    void run();

    sf::Clock clock;
    const float dt = 1.0f / 60.0f;
    gameDataRef data = std::make_shared<GameData>();
};


#endif //GAME_H
