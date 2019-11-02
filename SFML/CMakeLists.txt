cmake_minimum_required(VERSION 3.14)
project(SFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML main.cpp)
target_link_libraries(SFML sfml-graphics sfml-audio sfml-window sfml-system)
