
#include "Polygon.h"
#include <iostream>
#include <cmath>

double Polygon::getDistance(Point a, Point b) const {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

Polygon::Polygon(const std::vector<Point>& v) : vertices(v) {}

double Polygon::getPerimeter() const {
    double perimeter = 0;
    size_t n = vertices.size();
    if (n < 2) return 0;

    for (size_t i = 0; i < n; ++i) {
        perimeter += getDistance(vertices[i], vertices[(i + 1) % n]);
    }
    return perimeter;
}

double Polygon::getArea() const {
    double area = 0.0;
    size_t n = vertices.size();
    if (n < 3) return 0;

    for (size_t i = 0; i < n; ++i) {
        area += (vertices[i].x * vertices[(i + 1) % n].y - vertices[(i + 1) % n].x * vertices[i].y);
    }
    return std::abs(area) / 2.0;
}

bool Polygon::isConvex() const {
    size_t n = vertices.size();
    if (n < 4) return true;

    bool hasNegative = false;
    bool hasPositive = false;

    for (size_t i = 0; i < n; ++i) {
        Point p0 = vertices[i];
        Point p1 = vertices[(i + 1) % n];
        Point p2 = vertices[(i + 2) % n];

        double crossProduct = (p1.x - p0.x) * (p2.y - p1.y) - (p1.y - p0.y) * (p2.x - p1.x);

        if (crossProduct < 0) {
            hasNegative = true;
        }
        if (crossProduct > 0) {
            hasPositive = true;
        }

        if (hasNegative && hasPositive) {
            return false;
        }
    }
    return true;
}

void Polygon::print() const {
    std::cout << vertices.size() << "-sided Polygon";
}