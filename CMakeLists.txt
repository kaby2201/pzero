cmake_minimum_required(VERSION 3.14)
project(pzero)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")

set(SOURCE_FILES
        main.cpp
        DEFINITIONS.hpp
        engine/machine.cpp
        engine/machine.h
        engine/asset_manager.h
        engine/input_manager.cpp
        engine/input_manager.h
        state/game.cpp
        state/game.h
        state/pause_state.h
        state/pause_state.cpp
        state/state.h
        state/splash_state.cpp
        state/splash_state.h
        state/main_menu_state.cpp
        state/main_menu_state.h
        state/setting_state.cpp
        state/ingame_state.cpp
        state/ingame_state.h
        state/setting_state.h
        state/state_help.cpp

        state/state_help.h
        #In game files
        state/in_game/include/Assets.h
        state/in_game/include/Blackhole.h
        state/in_game/include/Camera.h
        state/in_game/include/Constants.h
        state/in_game/include/Direction.h
        state/in_game/include/ICollideable.h
        state/in_game/include/IRenderable.h
        state/in_game/include/Player.h
        state/in_game/include/SpriteInfo.h
        state/in_game/include/SpriteObject.h
        state/in_game/include/World.h
        state/in_game/include/WorldManager.h
        state/in_game/include/WorldObject.h
        state/in_game/src/Assets.cpp
        state/in_game/src/Blackhole.cpp
        state/in_game/src/Camera.cpp
        state/in_game/src/Player.cpp
        state/in_game/src/SpriteObject.cpp
        state/in_game/src/World.cpp
        state/in_game/src/WorldManager.cpp
        state/in_game/src/WorldObject.cpp
        state/state_help.h state/animation.cpp state/animation.h state/player.cpp state/player.h)


add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . )

target_link_libraries (pzero sfml-graphics sfml-window sfml-system sfml-audio)
