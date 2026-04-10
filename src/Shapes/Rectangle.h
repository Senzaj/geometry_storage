#pragma once

#include "Shape.h"

class Rectangle: public Shape{
public:
    explicit Rectangle(double width, double height);
    [[nodiscard("No usage")]] double getWidth() const;
    [[nodiscard("No usage")]] double getHeight() const;
    double accept(Calculator &calc) override;
private:
    double width;
    double height;
};
