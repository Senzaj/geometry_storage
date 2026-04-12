#pragma once
#include <stdexcept>
#include <string>
#include <unordered_map>

enum class ShapeType {
    Circle,
    Rectangle,
    Triangle,
};

inline std::string shapeTypeToString(ShapeType shapeType) {
    switch (shapeType) {
        case ShapeType::Circle:
            return "Circle";
        case ShapeType::Rectangle:
            return "Rectangle";
        case ShapeType::Triangle:
            return "Triangle";
        default:
            return "unknown";
    }
}

inline ShapeType stringToShapeType(const std::string& str) {
    static const std::pmr::unordered_map<std::string, ShapeType> map = {
        {"circle", ShapeType::Circle},
        {"rectangle", ShapeType::Rectangle},
        {"triangle", ShapeType::Triangle}
    };

    auto iterator = map.find(str);
    if (iterator != map.end())
        return iterator->second;

    throw std::invalid_argument("Invalid shape type: " + str);
}
