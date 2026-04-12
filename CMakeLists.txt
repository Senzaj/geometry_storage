cmake_minimum_required(VERSION 4.2)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 26)

add_executable(C_MAIN src/main.cpp
        src/Random/RandomGenerator.cpp
        src/Random/RandomGenerator.h
        src/Shapes/Shape.h
        src/Shapes/Circle.cpp
        src/Shapes/Circle.h
        src/Calculator/Calculator.h
        src/Calculator/AreaCalculator.cpp
        src/Calculator/AreaCalculator.h
        src/Calculator/PerimeterCalculator.cpp
        src/Calculator/PerimeterCalculator.h
        src/Shapes/Shape.cpp
        src/Calculator/Calculator.cpp
        src/Shapes/Rectangle.cpp
        src/Shapes/Rectangle.h
        src/Shapes/Triangle.cpp
        src/Shapes/Triangle.h
        src/Libs/sqlite3.h
        src/Libs/sqlite3.c
        src/DatabaseManager/DatabaseManager.cpp
        src/DatabaseManager/DatabaseManager.h
        src/ShapeType/ShapeType.cpp
        src/ShapeType/ShapeType.h
)
