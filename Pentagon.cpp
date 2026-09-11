#include "Pentagon.h"
#include <iostream>
#include <stdexcept>

Pentagon::Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5)
    : Polygon({p1, p2, p3, p4, p5}) {

    if (vertices.size() != 5) {
        throw std::invalid_argument("Pentagon must have 5 vertices.");
    }
}

void Pentagon::print() const {
    std::cout << "Pentagon";
}