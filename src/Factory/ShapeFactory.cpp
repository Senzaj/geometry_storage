#include "ShapeFactory.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"

ShapeFactory::ShapeFactory(int startId ,AreaCalculator areaCalculator, PerimeterCalculator perimeterCalculator, RandomGenerator randomGenerator) {
    id=startId;
    this->areaCalculator = &areaCalculator;
    this->perimeterCalculator = &perimeterCalculator;
    this->randomGenerator = &randomGenerator;
}

ShapeFactory::~ShapeFactory() {
    delete areaCalculator;
    delete perimeterCalculator;
    delete randomGenerator;
}

Circle* ShapeFactory::createCircle(double radius) const {
    Circle* circle = new Circle(id++, radius, areaCalculator, perimeterCalculator);
    return circle;
}

Circle* ShapeFactory::createCircle(double radius, double area, double perimeter) const {
    Circle* circle = new Circle(id++, radius, area, perimeter);
    return circle;
}

Rectangle* ShapeFactory::createRectangle(double width, double height) const {
    Rectangle* rectangle = new Rectangle(id++, width, height, areaCalculator, perimeterCalculator);
    return rectangle;
}

Rectangle* ShapeFactory::createRectangle(double width, double height, double area, double perimeter) const {
    Rectangle* rectangle = new Rectangle(id++, width, height, area, perimeter);
    return rectangle;
}

Triangle* ShapeFactory::createTriangle(double sideA, double sideB, double sideC) const {
    Triangle* triangle = new Triangle(id++, sideA, sideB, sideC, areaCalculator, perimeterCalculator);
    return triangle;
}

Triangle* ShapeFactory::createTriangle(double sideA, double sideB, double sideC, double area, double perimeter) const {
    Triangle* triangle = new Triangle(id++, sideA, sideB, sideC, area, perimeter);
    return triangle;
}
