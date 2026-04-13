#include "Circle.h"
#include <stdexcept>

Circle::Circle(int id, double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator): Shape(id) {
    if (radius <= 0)
        throw std::invalid_argument("Radius must be positive");

    this->radius = radius;
    Circle::accept(*perimeterCalculator);
    Circle::accept(*areaCalculator);
}

Circle::Circle(int id, double radius, double area, double perimeter) : Shape(id, area, perimeter) {
    this->radius = radius;
}

void Circle::accept(Calculator& calc) {
    calc.visit(this);
}

ShapeType Circle::getType() const {
    return ShapeType::Circle;
}

double Circle::getRadius() const {return radius;};