#include "Rectangle.h"
#include "../Calculator/Calculator.h"

Rectangle::Rectangle(double width, double height, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {
    this->width = width;
    this->height = height;
    Rectangle::setPerimeter(Rectangle::accept(*perimeterCalculator));
    Rectangle::setArea(Rectangle::accept(*areaCalculator));
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::accept(Calculator &calc)  {
    return calc.visit(this);
}
