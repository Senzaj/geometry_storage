#include "PerimeterCalculator.h"
#include <cmath>
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"

double PerimeterCalculator::visit(Circle* circle) {
    double perimeter = 2 * M_PI * circle->getRadius();
    circle->setPerimeter(perimeter);
    return perimeter;
}

double PerimeterCalculator::visit(Rectangle* rectangle) {
    double perimeter = 2 * rectangle->getWidth() + 2 * rectangle->getHeight();
    rectangle->setPerimeter(perimeter);
    return perimeter;
}

double PerimeterCalculator::visit(Triangle* triangle) {
    double perimeter = triangle->getASide() + triangle->getBSide() + triangle->getCSide();
    triangle->setPerimeter(perimeter);
    return perimeter;
}
