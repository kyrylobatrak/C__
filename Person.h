#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    unsigned byear;

public:
    Person();

    // Віртуальний деструктор (важливо для наслідування)
    virtual ~Person();

    friend std::ostream& operator<<(std::ostream& os, const Person& p);

    friend std::istream& operator>>(std::istream& is, Person& p);

    std::string getName() const;
};

#endif // PERSON_H