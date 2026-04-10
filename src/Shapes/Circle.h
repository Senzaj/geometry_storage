#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Circle: public Shape {
    public:
        explicit Circle(double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
        [[nodiscard("No usage")]] double getRadius() const;
        void accept(Calculator &calc) override;
    private:
        double radius;
};
