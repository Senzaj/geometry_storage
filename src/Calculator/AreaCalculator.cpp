#include "AreaCalculator.h"
#include "../Shapes/Circle.h"
#include "cmath"
#include "../Shapes/Rectangle.h"

double AreaCalculator::visit(Circle* circle) {
    const double area = 3.14 * std::pow(circle->getRadius(), 2);
    circle->setArea(area);
    return area;
}

double AreaCalculator::visit(Rectangle* rectangle) {
    const double area = rectangle->getWidth() * rectangle->getHeight();
    rectangle->setArea(area);
    return area;
}

double AreaCalculator::visit(Triangle* triangle) {
    //calculate half perimeter
    //calculate area
}

