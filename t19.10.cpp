#include <iostream>
#include <string>
#include <list>

class Auto {
public:
    std::string name;
    std::string model;
    std::string number;
    int owner_id;

    Auto() : owner_id(0) {}

    Auto(std::string n, std::string m, std::string num, int id)
        : name(n), model(m), number(num), owner_id(id) {}

    friend std::istream& operator>>(std::istream& is, Auto& car) {
        std::cout << "Enter name: ";
        is >> car.name;
        std::cout << "Enter model: ";
        is >> car.model;
        std::cout << "Enter number: ";
        is >> car.number;
        std::cout << "Enter owner ID: ";
        is >> car.owner_id;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Auto& car) {
        os << "Name: " << car.name << ", Model: " << car.model
           << ", Number: " << car.number << ", Owner ID: " << car.owner_id;
        return os;
    }
};

int main() {
    std::list<Auto> car_list;

    car_list.push_back(Auto("Toyota", "Camry", "AA1234BB", 101));
    car_list.push_back(Auto("BMW", "X5", "KA7777KA", 102));
    car_list.push_back(Auto("Audi", "A6", "BC5678AP", 103));
    car_list.push_back(Auto("Mercedes", "S-Class", "AI9999AI", 104));

    car_list.sort([](const Auto& a, const Auto& b) {
        return a.name < b.name;
    });

    std::cout << "Sorted License Numbers (by car name):" << std::endl;
    for (const auto& car : car_list) {
        std::cout << car.number << std::endl;
    }

    return 0;
}