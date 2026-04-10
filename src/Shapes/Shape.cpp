#include "Shape.h"

Shape::Shape() {}

double Shape::accept(Calculator &calc){}

void Shape::setArea(double area) {
    this->area = area;
}

void Shape::setPerimeter(double perimeter) {
    this->perimeter = perimeter;
}

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}
