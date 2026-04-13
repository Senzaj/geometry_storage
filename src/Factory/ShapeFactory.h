#pragma once
#include "../Calculator/AreaCalculator.h"
#include "../Calculator/PerimeterCalculator.h"
#include "../Random/RandomGenerator.h"
#include "../Shapes/Shape.h"

class ShapeFactory {
public:
    explicit ShapeFactory(AreaCalculator areaCalculator, PerimeterCalculator perimeterCalculator, RandomGenerator randomGenerator);
    virtual ~ShapeFactory();

    Circle* createCircle(double radius) const;
    Circle* createCircle(double radius, double area, double perimeter) const;

    Rectangle* createRectangle(double width, double height) const;
    Rectangle* createRectangle(double width, double height, double area, double perimeter) const;

    Triangle* createTriangle(double sideA, double sideB, double sideC) const;
    Triangle* createTriangle(double sideA, double sideB, double sideC, double area, double perimeter) const;
private:
    Shape* createShape() const;
    AreaCalculator* areaCalculator;
    PerimeterCalculator* perimeterCalculator;
    RandomGenerator* randomGenerator;
};

