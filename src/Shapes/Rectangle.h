#pragma once
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

#include "Shape.h"

class Rectangle: public Shape{
public:
    explicit Rectangle(double width, double height, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
    [[nodiscard("No usage")]] double getWidth() const;
    [[nodiscard("No usage")]] double getHeight() const;
    double accept(Calculator &calc) override;
private:
    double width;
    double height;
};
