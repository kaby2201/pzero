cmake_minimum_required(VERSION 3.15)
project(pzero)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")

set(SOURCE_FILES
        main.cpp
        DEFINITIONS.hpp
        engine/machine.cpp
        engine/machine.h
        state/state_main_manu.cpp
        state/state_main_manu.h
        state/state.h
        engine/resource_manager.h
        state/stateexit.cpp
        state/stateexit.h
        config/config.cpp
        config/config.h
        engine/game.cpp
        engine/game.h state/game_state.cpp state/game_state.h)

add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . ext/jsoncpp)
target_link_libraries (pzero sfml-graphics sfml-window sfml-system)