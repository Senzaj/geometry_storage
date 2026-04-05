cmake_minimum_required(VERSION 4.2)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 26)

add_executable(C_MAIN src/main.cpp
        src/Random/RandomGenerator.cpp
        src/Random/RandomGenerator.h
)
