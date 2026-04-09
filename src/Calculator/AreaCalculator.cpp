#include "AreaCalculator.h"
#include "../Shapes/Circle.h"
#include "cmath"

double AreaCalculator::visit(const Circle& circle) {
    return 3.14 * std::pow(circle.getRadius(), 2);
}
