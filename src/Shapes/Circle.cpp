#include "Circle.h"
#include "../Calculator/Calculator.h"

Circle::Circle(double radius){
    this->radius = radius;
};

double Circle::accept(Calculator& calc) {
    return calc.visit(this);
}

double Circle::getRadius() const {return radius;};