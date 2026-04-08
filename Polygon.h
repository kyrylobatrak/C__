#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include "Point.h"
#include <vector>

class Polygon : public Figure {
protected:
    std::vector<Point> vertices;

    double getDistance(Point a, Point b) const;

public:
    Polygon(const std::vector<Point>& v);

    virtual ~Polygon() {}

    double getPerimeter() const override;
    double getArea() const override;
    bool isConvex() const override;
    void print() const override;
};

#endif // POLYGON_H