#include "Triangle.h"
#include <stdexcept>
#include "../Calculator/Calculator.h"

Triangle::Triangle(double aSide, double bSide, double cSide,  AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator) {
    if (aSide <= 0 || bSide <= 0 || cSide <= 0)
        throw std::invalid_argument("All sides must be positive");

    this->aSide = aSide;
    this->bSide = bSide;
    this->cSide = cSide;
    Triangle::accept(*perimeterCalculator);
    Triangle::accept(*areaCalculator);
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

void Triangle::accept(Calculator &calc) {
    calc.visit(this);
}

ShapeType Triangle::getType() const {
    return ShapeType::Triangle;
}
