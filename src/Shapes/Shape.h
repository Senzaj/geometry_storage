#pragma once
#include "../ShapeType/ShapeType.h"

class Shape {
public:
    virtual ~Shape() = default;

    virtual void accept(class Calculator& calc) = 0;

    virtual void setArea(double area);
    virtual void setPerimeter(double perimeter);

    [[nodiscard("no usage")]] int getId() const;
    [[nodiscard("No usage")]] virtual ShapeType getType() const = 0;
    [[nodiscard("No usage")]] double getArea() const;
    [[nodiscard("No usage")]] double getPerimeter() const;
protected:
    explicit Shape(int id);
    explicit Shape(int id, double area, double perimeter);
    int id;
    double area;
    double perimeter;
};


