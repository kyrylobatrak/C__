#include "Person.h"

Person::Person() : byear(0) {

}

Person::~Person() {}

std::string Person::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Surname: " << p.name << "\n";
    os << "Year of birth: " << p.byear;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    std::cout << "Enter surname: ";
    is >> p.name;
    std::cout << "Enter year of birth: ";
    is >> p.byear;
    return is;
}