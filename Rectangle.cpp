#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(Point tl, Point br) : topLeft(tl), bottomRight(br) {}

double Rectangle::getSideA() const {
    return std::abs(bottomRight.x - topLeft.x);
}

double Rectangle::getSideB() const {
    return std::abs(topLeft.y - bottomRight.y);
}

double Rectangle::getPerimeter() const {
    return 2 * (getSideA() + getSideB());
}

double Rectangle::getArea() const {
    return getSideA() * getSideB();
}

bool Rectangle::isConvex() const {
    return true;
}

void Rectangle::print() const {
    std::cout << "Rectangle at (" << topLeft.x << ", " << topLeft.y << ") to ("
              << bottomRight.x << ", " << bottomRight.y << ")";
}