#pragma once

class Circle;
class Rectangle;
class Triangle;

class Calculator {
public:
    virtual double visit( Circle* circle) = 0;
    virtual double visit( Rectangle* rectangle) = 0;
    virtual double visit( Triangle* triangle) = 0;
    virtual ~Calculator() = default;
};

