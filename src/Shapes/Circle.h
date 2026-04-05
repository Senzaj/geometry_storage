#pragma once
#include "Shape.h"

class Circle: public Shape {
    public:
        Circle(double radius);
        double getRadius() const;
    private:
        double radius;
};
