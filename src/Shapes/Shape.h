#pragma once

class Shape {
public:
    virtual ~Shape() = default;
    virtual double accept(class Calculator& calc);
    virtual void setArea(double area);
    virtual void setPerimeter(double perimeter);
    [[nodiscard("No usage")]] virtual double getArea() const;
    [[nodiscard("No usage")]] virtual double getPerimeter() const;
protected:
    explicit Shape();
    double area;
    double perimeter;
};


