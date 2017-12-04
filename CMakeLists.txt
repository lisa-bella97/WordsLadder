cmake_minimum_required(VERSION 3.8)
project(WordsLadder)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SOURCE_FILES include/WordsGraph.hpp sources/WordsGraph.cpp)
add_executable(WordsLadder ${SOURCE_FILES} sources/main.cpp)
add_executable(Tests ${SOURCE_FILES} tests/catch.hpp tests/main.cpp tests/01.cpp tests/02.cpp tests/03.cpp tests/04.cpp tests/05.cpp tests/06.cpp tests/07.cpp)