#include "AreaCalculator.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../shapes/Triangle.h"
#include <cmath>

double AreaCalculator::visit(Circle* circle) {
    const double area = M_PI * std::pow(circle->getRadius(), 2);
    circle->setArea(area);
    return area;
}

double AreaCalculator::visit(Rectangle* rectangle) {
    const double area = rectangle->getWidth() * rectangle->getHeight();
    rectangle->setArea(area);
    return area;
}

double AreaCalculator::visit(Triangle* triangle) {
    const double hp = triangle->getPerimeter()/2;
    const double area = std::sqrt(hp * (hp - triangle->getASide())*(hp - triangle->getBSide())*(hp - triangle->getCSide()));
    return area;
}

