#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Triangle: public Shape {
public:
    explicit Triangle (double aSide, double bSide, double cSide,
        AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
    [[nodiscard("no usage")]] double getASide() const;
    [[nodiscard("no usage")]] double getBSide() const;
    [[nodiscard("no usage")]] double getCSide() const;
    void accept(Calculator &calc) override;
private:
    double aSide;
    double bSide;
    double cSide;
};

