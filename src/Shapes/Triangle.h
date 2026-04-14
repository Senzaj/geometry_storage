#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Triangle: public Shape {
public:
    Triangle (int id, double aSide, double bSide, double cSide,
        AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
    Triangle (int id, double aSide, double bSide, double cSide, double area, double perimeter);

    void accept(Calculator &calc) override;

    [[nodiscard("No usage")]] ShapeType getType() const override;
    [[nodiscard("no usage")]] double getASide() const;
    [[nodiscard("no usage")]] double getBSide() const;
    [[nodiscard("no usage")]] double getCSide() const;
private:
    double aSide;
    double bSide;
    double cSide;
};

