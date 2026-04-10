#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Circle: public Shape {
    public:
        explicit Circle(double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
        [[nodiscard("No usage")]] double getRadius() const;
        double accept(Calculator &calc) override;
    private:
        double radius;
};
