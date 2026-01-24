#include <iostream>

using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() = 0;
    virtual void printInfo() = 0;
};

class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) {
            width = w;
            height = h;
        }

    double area() override{
            return width * height;
        }

    void printInfo() override{
            cout << "I am rectangle" << endl;
        }
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) {
            radius = r;
        }

    double area() override {
            return 3.14 * radius * radius;
        }

    void printInfo() override {
            cout << "I am circle" << endl;
        }
};

int main() {
    Shape *s1 = new Rectangle(10, 5);
    Shape *s2 = new Circle(5);

    s1 -> printInfo();
    s2 -> printInfo();

    cout << "Area rectangle: " << s1 -> area() << endl;
    cout << "Area circle: " << s2 -> area() << endl;

    delete s1;
    delete s2;

    return 0;
}