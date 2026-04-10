#include "Triangle.h"
#include "../Calculator/Calculator.h"

Triangle::Triangle(double aSide, double bSide, double cSide,  AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {
    this->aSide = aSide;
    this->bSide = bSide;
    this->cSide = cSide;
    Triangle::setPerimeter(Triangle::accept(*perimeterCalculator));
    Triangle::setArea(Triangle::accept(*areaCalculator));
}

double Triangle::getASide() const {
    return aSide;
}

double Triangle::getBSide() const {
    return bSide;
}

double Triangle::getCSide() const {
    return cSide;
}

double Triangle::accept(Calculator &calc) {
    return calc.visit(this);
}
