#include <format>
#include <iostream>
#include <memory>

#include "Calculator/AreaCalculator.h"
#include "Shapes/Circle.h"
#include "Shapes/Rectangle.h"

int main() {
    std::unique_ptr<AreaCalculator> areaCalc = std::make_unique<AreaCalculator>();
    double radius = 4;
    double width = 5;
    double height = 6;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(width, height);
    circle->accept(*areaCalc);
    rectangle->accept(*areaCalc);
    std::cout << "Circle area = " << std::format("{:.2f}", circle->getArea()) << std::endl;
    std::cout << "Rectangle area = " << std::format("{:.2f}", rectangle->getArea());
    return 0;
}
