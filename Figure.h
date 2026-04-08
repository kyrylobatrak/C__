#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:

    virtual ~Figure() {}

    virtual double getPerimeter() const = 0;

    virtual double getArea() const = 0;

    virtual bool isConvex() const = 0;

    virtual void print() const = 0;
};

#endif // FIGURE_H