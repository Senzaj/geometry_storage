#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Rectangle: public Shape{
public:
    explicit Rectangle(int id, double width, double height, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
    explicit Rectangle(int id, double width, double height, double area, double perimeter);

    void accept(Calculator &calc) override;

    [[nodiscard("No usage")]] ShapeType getType() const override;
    [[nodiscard("No usage")]] double getWidth() const;
    [[nodiscard("No usage")]] double getHeight() const;
private:
    double width;
    double height;
};
