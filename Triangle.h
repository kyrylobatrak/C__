#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include "Point.h"

class Triangle : public Figure {
private:
    Point vertices[3];

    double getDistance(Point a, Point b) const;

public:
    Triangle(Point p1, Point p2, Point p3);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    double getPerimeter() const override;
    double getArea() const override;
    bool isConvex() const override;
    void print() const override;
};

#endif // TRIANGLE_H