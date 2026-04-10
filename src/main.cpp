#include <format>
#include <iostream>
#include <memory>

#include "Calculator/AreaCalculator.h"
#include "Shapes/Circle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Triangle.h"

int main() {
    std::unique_ptr<AreaCalculator> areaCalc = std::make_unique<AreaCalculator>();
    std::unique_ptr<PerimeterCalculator> perimeterCalc = std::make_unique<PerimeterCalculator>();

    double radius = 4;
    double width = 5;
    double height = 6;
    double a = 3;
    double b = 4;
    double c = 5;

    #if 0
    double* ptr = &radius;
    double* (&dbl_ptr) = ptr;
    double* (&dbl_ptr_snd) = dbl_ptr;
    std::cout << dbl_ptr_snd << std::endl;
    #endif


    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius, &*areaCalc, &*perimeterCalc);
    std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(width, height, &*areaCalc, &*perimeterCalc);
    std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(a, b, c, &*areaCalc, &*perimeterCalc);

    std::cout << "Circle area = " << std::format("{:.2f}", circle->getArea()) << std::endl;
    std::cout << "Rectangle area = " << std::format("{:.2f}", rectangle->getArea()) << std::endl;
    std::cout << "Triangle area = " << std::format("{:.2f}", triangle->getArea());
    return 0;
}
