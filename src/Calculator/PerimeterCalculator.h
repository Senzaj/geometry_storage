#pragma once
#include "Calculator.h"

class PerimeterCalculator: public Calculator {
public:
    double visit(Circle* circle) override;
    double visit(Rectangle* rect) override;
    double visit(Triangle* triangle) override;
};

