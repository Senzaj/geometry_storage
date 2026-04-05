#pragma once
#include "ShapeType.h"

class Shape {
public:
    explicit Shape(ShapeType type);
    ShapeType getType() const;
    virtual ~Shape() = default;
    virtual double getArea();
    virtual double getPerimeter();
protected:
    ShapeType type;
    double area;
    double perimeter;
};


