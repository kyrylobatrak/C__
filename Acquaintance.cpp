#include "Acquaintance.h"

Acquaintance::Acquaintance() : Person() {}

void Acquaintance::setPhoneNumber(const std::string& newNumber) {
    phoneNumber = newNumber;
}

std::ostream& operator<<(std::ostream& os, const Acquaintance& a) {
    os << static_cast<const Person&>(a);

    os << "\nPhone number: " << a.phoneNumber;
    return os;
}

std::istream& operator>>(std::istream& is, Acquaintance& a) {
    is >> static_cast<Person&>(a);

    std::cout << "Enter phone number: ";
    is >> a.phoneNumber;
    return is;
}

void Acquaintance::writeToFile(std::ostream& file) const {
    file << name << std::endl;
    file << byear << std::endl;
    file << phoneNumber << std::endl;
}

void Acquaintance::readFromFile(std::istream& file) {
    file >> name >> byear >> phoneNumber;
}