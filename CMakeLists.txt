cmake_minimum_required(VERSION 3.15)
project(pzero)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")

set(SOURCE_FILES
        main.cpp
        DEFINITIONS.hpp state/state.h engine/machine.cpp engine/machine.h engine/asset_manager.h engine/input_manager.cpp engine/input_manager.h state/splash_state.cpp state/splash_state.h state/game.cpp state/game.h state/main_menu_state.cpp state/main_menu_state.h state/game_arena.cpp state/game_arena.h state/pause_state.cpp state/pause_state.h)

add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . ext/jsoncpp)
target_link_libraries (pzero sfml-graphics sfml-window sfml-system sfml-audio)
