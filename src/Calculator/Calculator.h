#pragma once

class Circle;

class Calculator {
public:
    virtual double visit(const Circle& circle) = 0;
    virtual ~Calculator() = default;
};

