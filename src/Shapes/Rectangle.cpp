#include "Rectangle.h"

#include <stdexcept>

#include "../Calculator/Calculator.h"

Rectangle::Rectangle(double width, double height, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {

    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Both width and height must be positive");

    this->width = width;
    this->height = height;
    Rectangle::accept(*perimeterCalculator);
    Rectangle::accept(*areaCalculator);
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::accept(Calculator &calc)  {
    calc.visit(this);
}

ShapeType Rectangle::getType() const {
    return ShapeType::Rectangle;
}
