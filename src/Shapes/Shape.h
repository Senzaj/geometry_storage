#pragma once

class Shape {
public:
    virtual ~Shape() = default;
    virtual void accept(class Calculator& calc) = 0;
    virtual void setArea(double area);
    virtual void setPerimeter(double perimeter);
    [[nodiscard("No usage")]] double getArea() const;
    [[nodiscard("No usage")]] double getPerimeter() const;
protected:
    explicit Shape();
    double area;
    double perimeter;
};


