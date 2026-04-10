#include "Circle.h"

Circle::Circle(double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {
    this->radius = radius;
    Circle::setPerimeter(Circle::accept(*perimeterCalculator));
    Circle::setArea(Circle::accept(*areaCalculator));
}

double Circle::accept(Calculator& calc) {
    return calc.visit(this);
}

double Circle::getRadius() const {return radius;};