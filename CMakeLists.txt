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
        state/state.h
        state/splash_state.cpp
        state/splash_state.h
        state/main_menu_state.cpp
        state/main_menu_state.h
        state/setting_state.cpp
        state/setting_state.h)

add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . ext/jsoncpp)
target_link_libraries (pzero sfml-graphics sfml-window sfml-system sfml-audio)
