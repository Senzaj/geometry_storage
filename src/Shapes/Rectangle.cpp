#include "Rectangle.h"
#include "../Calculator/Calculator.h"

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::accept(Calculator &calc)  {
    return calc.visit(this);
}
