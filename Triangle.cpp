#include "Triangle.h"
#include <iostream>
#include <cmath>

double Triangle::getDistance(Point a, Point b) const {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
}

double Triangle::getSideA() const {
    return getDistance(vertices[0], vertices[1]);
}

double Triangle::getSideB() const {
    return getDistance(vertices[1], vertices[2]);
}

double Triangle::getSideC() const {
    return getDistance(vertices[2], vertices[0]);
}

double Triangle::getPerimeter() const {
    return getSideA() + getSideB() + getSideC();
}

double Triangle::getArea() const {
    double a = getSideA();
    double b = getSideB();
    double c = getSideC();
    double s = getPerimeter() / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Triangle::isConvex() const {
    return true;
}

void Triangle::print() const {
    std::cout << "Triangle with vertices at (" << vertices[0].x << ", " << vertices[0].y << "), ("
              << vertices[1].x << ", " << vertices[1].y << "), ("
              << vertices[2].x << ", " << vertices[2].y << ")";
}