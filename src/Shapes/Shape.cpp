#include "Shape.h"

Shape::Shape(ShapeType type) {
    this->type = type;
};

ShapeType Shape::getType() const {return type;}


