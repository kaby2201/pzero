#include <state/in_game/include/Assets.h>
#include <DEFINITIONS.hpp>


std::map<std::string, SpriteInfo> Assets::sprites;

void Assets::loadAssets(){
    sprites["ammocrate"]        = SpriteInfo("resources/sprite/ammocrate.png");
    sprites["grassblock"]       = SpriteInfo("resources/sprite/grass_block.png");
    sprites["tilegrassblock"]   = SpriteInfo("resources/sprite/grass_block_tileable.png");
    sprites["tallrock"]         = SpriteInfo("resources/sprite/tall_rock.png");
    sprites["ladder"]           = SpriteInfo("resources/sprite/ladder.png");
    sprites["cloud"]            = SpriteInfo("resources/sprite/cloud.png");
    sprites["background"]       = SpriteInfo(SPLASH_SCREEN_BACKGROUND);
    sprites["blackhole"]        = SpriteInfo("resources/sprite/blackhole.png");

    sprites["bluepeewee"]       = SpriteInfo("resources/sprite/bluepeewee.png", 36, 6);
    sprites["bluepeewee"].mHitBox = sf::FloatRect(20.f, 10.f, 24.f, 44.f);
    sprites["bridge"] = SpriteInfo("resources/sprite/bridge.png");
    sprites["bridge"].mHitBox = sf::FloatRect(6.f, 37.f, 140.f, 6.f);
}
