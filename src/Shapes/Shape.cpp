#include "Shape.h"

Shape::Shape() : area(0), perimeter(0) {
}

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
