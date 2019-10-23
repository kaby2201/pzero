cmake_minimum_required(VERSION 3.15)
project(pzero)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")

set(SOURCE_FILES
        main.cpp
        engine/machine.cpp
        engine/machine.h
        state/state_main_manu.cpp
        state/state_main_manu.h
        state/state.h
        state/stateexit.cpp
        state/stateexit.h config/config.cpp config/config.h engine/resource_manager.h)

add_executable(pzero ${SOURCE_FILES})
target_include_directories(pzero PUBLIC . ext/jsoncpp)