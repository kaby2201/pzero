#ifndef PZERO_ASSETS_H
#define PZERO_ASSETS_H


#include "sprite_info.h"

struct Assets {
    void loadAssets();

    static std::map<std::string, SpriteInfo> sprites;
};


#endif //PZERO_ASSETS_H
