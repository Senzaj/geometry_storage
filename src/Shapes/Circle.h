#pragma once
#include "Shape.h"

class Circle: public Shape {
    public:
        explicit Circle(double radius);
        [[nodiscard("No usage")]] double getRadius() const;
        double accept(Calculator &calc) override;
    private:
        double radius;
};
