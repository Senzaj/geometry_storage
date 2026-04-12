#include <memory>
#include <vector>

#include "Calculator/AreaCalculator.h"
#include "Calculator/PerimeterCalculator.h"
#include "Shapes/Circle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Triangle.h"

std::vector<std::shared_ptr<Shape>> initFigures();

int main() {
    std::vector<std::shared_ptr<Shape>> shapes = initFigures();

    return 0;
}

std::vector<std::shared_ptr<Shape>> initFigures() {
    std::unique_ptr<AreaCalculator> areaCalc = std::make_unique<AreaCalculator>();
    std::unique_ptr<PerimeterCalculator> perimeterCalc = std::make_unique<PerimeterCalculator>();

    double radius = 4;
    double width = 5;
    double height = 6;
    double a = 3;
    double b = 4;
    double c = 5;

    std::vector<std::shared_ptr<Shape>> shapes;

    auto circle = std::make_shared<Circle>(radius, &*areaCalc, &*perimeterCalc);
    auto rectangle = std::make_shared<Rectangle>(width, height, &*areaCalc, &*perimeterCalc);
    auto triangle = std::make_shared<Triangle>(a, b, c, &*areaCalc, &*perimeterCalc);

    shapes.push_back(circle);
    shapes.push_back(rectangle);
    shapes.push_back(triangle);

    return shapes;
}


