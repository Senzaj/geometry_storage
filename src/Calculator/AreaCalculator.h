#pragma once
#include "Calculator.h"

class AreaCalculator: public Calculator {
public:
    double visit(const Circle& circle) override;
};
