cmake_minimum_required(VERSION 3.8)
project(WordsLadder)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SOURCE_FILES sources/main.cpp include/WordsGraph.hpp sources/WordsGraph.cpp)
add_executable(WordsLadder ${SOURCE_FILES})