#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include "Point.h"

class Rectangle : public Figure {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(Point tl, Point br);

    double getSideA() const;
    double getSideB() const;

    double getPerimeter() const override;
    double getArea() const override;
    bool isConvex() const override;
    void print() const override;
};

#endif // RECTANGLE_H