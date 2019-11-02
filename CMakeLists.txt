cmake_minimum_required(VERSION 3.15)
project(pzero)

set(CMAKE_CXX_STANDARD 14)

add_executable(pzero main.cpp Menu.cpp Menu.h)

target_link_libraries(pzero sfml-graphics sfml-window sfml-system jsoncpp)