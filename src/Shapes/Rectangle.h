#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Rectangle: public Shape{
public:
    explicit Rectangle(double width, double height, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
    [[nodiscard("No usage")]] double getWidth() const;
    [[nodiscard("No usage")]] double getHeight() const;
    void accept(Calculator &calc) override;
private:
    double width;
    double height;
};
