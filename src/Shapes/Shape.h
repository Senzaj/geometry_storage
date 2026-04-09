#pragma once

class Shape {
public:
    virtual ~Shape() = default;
    virtual double accept(class Calculator& calc) const;
protected:
    explicit Shape();
    double area;
    double perimeter;
};


