#include "Circle.h"

Circle::Circle(double radius): Shape (ShapeType::Circle){
    this->radius = radius;
};

double Circle::getRadius() const {return radius;};