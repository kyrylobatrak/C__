#include <iostream>
#include <vector>

using namespace std;

struct Car {
    double price;
    int age;
};

Car getCar() {
    Car car;
    cout << "Enter price: ";
    cin >> car.price;
    cout << "Enter age: ";
    cin >> car.age;
    return car;
}

double getAveragePrice(const vector<Car>& cars) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].age > 5) {
            sum += cars[i].price;
            count++;
        }
    }

    if (count == 0) {
        return 0.0;
    }

    return sum / count;
}

int main() {
    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    vector<Car> cars;

    for (int i = 0; i < n; i++) {
        cout << "\nCar #" << i + 1 << endl;
        cars.push_back(getCar());
    }

    if (n > 0) {
        double avgPrice = getAveragePrice(cars);

        if (avgPrice > 0) {
            cout << "\nAverage price of cars older than 5 years: " << avgPrice << endl;
        } else {
            cout << "\nNo cars older than 5 years found." << endl;
        }
    }

    return 0;
}