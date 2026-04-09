#include <iostream>
#include <memory>

#include "Calculator/AreaCalculator.h"
#include "Shapes/Circle.h"

int main() {
    std::unique_ptr<AreaCalculator> areaCalc = std::make_unique<AreaCalculator>();
    double radius = 4;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    std::cout  << "Circle area: " << circle->accept(*areaCalc) << std::endl;
    return 0;
}
