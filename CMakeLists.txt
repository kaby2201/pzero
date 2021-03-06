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
        state/game_arena.cpp
        state/game_arena.h
        state/setting_state.h
        state/state_help.cpp

        state/animation.cpp
        state/animation.h
        state/state_help.h
        state/menu_base.cpp
        state/menu_base.h
        game_character/character.cpp
        game_character/character.h
        state/game_header.h
        state/game_header.cpp
        state/platform.cpp
        state/platform.h
        map/map.cpp
        map/map.h

        objects/layer.cpp
        objects/layer.h
        objects/object.h
        objects/sprite.cpp
        objects/sprite.h

        game_character/character.h
        state/game_header.h
        state/game_header.cpp
        map/map.cpp map/map.h

        objects/layer.cpp
        objects/layer.h
        objects/object.h
        objects/sprite.cpp
        objects/sprite.h
        state/game_over_state.cpp
        state/game_over_state.h
        game_character/monster.cpp
        game_character/monster.h)



add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . )

target_link_libraries (pzero jsoncpp sfml-graphics sfml-window sfml-system sfml-audio)
