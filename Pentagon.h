#ifndef PENTAGON_H
#define PENTAGON_H

#include "Polygon.h"

class Pentagon : public Polygon {
public:
    Pentagon(Point p1, Point p2, Point p3, Point p4, Point p5);

    void print() const override;
};

#endif // PENTAGON_H