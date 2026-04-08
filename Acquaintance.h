#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Person.h"
#include <string>

class Acquaintance : public Person {
private:
    std::string phoneNumber;

public:
    Acquaintance();

    void setPhoneNumber(const std::string& newNumber);

    friend std::ostream& operator<<(std::ostream& os, const Acquaintance& a);
    friend std::istream& operator>>(std::istream& is, Acquaintance& a);

    void writeToFile(std::ostream& file) const;
    void readFromFile(std::istream& file);
};

#endif // ACQUAINTANCE_H