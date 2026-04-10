#pragma once
#include "Calculator.h"

class AreaCalculator: public Calculator {
public:
    double visit(Circle* circle) override;
    double visit(Rectangle* rectangle) override;
    double visit(Triangle* triangle) override;
};
