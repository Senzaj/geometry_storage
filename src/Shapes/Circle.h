#pragma once
#include "Shape.h"
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"

class Circle: public Shape {
    public:
        explicit Circle(int id, double radius, AreaCalculator* areaCalculator, PerimeterCalculator* perimeterCalculator);
        explicit Circle(int id, double radius, double area, double perimeter);

        void accept(Calculator &calc) override;

        [[nodiscard("No usage")]] ShapeType getType() const override;
        [[nodiscard("No usage")]] double getRadius() const;
    private:
        double radius;
};
