#include <iostream>

using namespace std;

class Rectangle {
    private:
        double width, height;
    public:
        Rectangle(double w, double h) {
            width = w;
            height = h;
            count++;
        }

        ~Rectangle() {
            count--;
            cout << "Object deleted. Remaining: " << count << endl;
        }

    static int count;

    double area() {
        return width * height;
    }

    void setWidth(double w) {
            if (w > 0) {
                width = w;
            } else {
                cout << "Error: Width cannot be negative!" << endl;
            }
        }

    double getHeight() {
            return height;
        }

    friend void doubleSize(Rectangle& rect);
};

int Rectangle::count = 0;

void doubleSize(Rectangle& rect) {
    rect.width *= 2;
    rect.height *= 2;
    cout << "HACKED" << endl;
}

int main() {
    // Rectangle rect(5, 5);
    // cout << "Area 1: " << rect.area() << endl;
    //
    // rect.setWidth(10);
    //
    // cout << "Area 2: " << rect.area() << endl;
    //
    // rect.setWidth(-50);
    //
    // cout << "Height: " << rect.getHeight() << endl;

    // Rectangle rect1(5, 5);
    // Rectangle rect2(2, 3);
    //
    // cout << "Total objects: " << Rectangle::count << endl;

    Rectangle rect1(5, 5); // count = 1

    cout << "Area 1: " << rect1.area() << endl;

    doubleSize(rect1);

    cout << "Area 2: " << rect1.area() << endl;


    // // Створюємо блок коду (окрема зона видимості)
    // {
    //     Rectangle rect2(2, 3); // count = 2
    //     cout << "Inside block: " << Rectangle::count << endl;
    // } // ТУТ rect2 помирає (бо блок закрився)! Спрацює деструктор.
    //
    // cout << "Outside block: " << Rectangle::count << endl;

    return 0;
}