#include "Circle.h"
#include <stdexcept>

Circle::Circle(double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {
    if (radius <= 0)
        throw std::invalid_argument("Radius must be positive");

    this->radius = radius;
    Circle::accept(*perimeterCalculator);
    Circle::accept(*areaCalculator);
}

void Circle::accept(Calculator& calc) {
    calc.visit(this);
}

double Circle::getRadius() const {return radius;};