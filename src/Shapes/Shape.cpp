#include "Shape.h"

Shape::Shape(int id) : area(0), perimeter(0) {
    this->id = id;
}

Shape::Shape(int id, double area, double perimeter) {
    this->id = id;
    this->area = area;
    this->perimeter = perimeter;
}

void Shape::setArea(double area) {
    this->area = area;
}

void Shape::setPerimeter(double perimeter) {
    this->perimeter = perimeter;
}

int Shape::getId() const {
    return id;
}

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}
