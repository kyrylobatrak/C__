#include "Person17.2.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <limits>

Person::Person(const std::string& name_val, const std::string& gender_val, const std::string& age_val)
    : name(name_val), gender(gender_val), age(age_val) {

    try {
        int age_int = std::stoi(age);
        if (age_int < 0) {
            throw std::invalid_argument("Error in Person constructor: Age cannot be negative.");
        }
    } catch (const std::exception& e) {
        throw std::invalid_argument("Error in Person constructor: Age is not a valid number.");
    }
}


std::string Person::getPIB() const {
    return this->name;
}

void Person::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter PIB (name): ";
    std::getline(std::cin, name);

    std::cout << "Enter gender: ";
    std::getline(std::cin, gender);

    std::cout << "Enter age: ";
    std::getline(std::cin, age);
    
    try {
        int age_int = std::stoi(age);
        if (age_int < 0) {
            throw std::invalid_argument("Error in input(): Age cannot be negative.");
        }
    } catch (const std::exception& e) {
        throw std::invalid_argument("Error in input(): Age is not a valid number.");
    }
}

void Person::print() const {
    std::cout << "--- Person ---" << std::endl;
    std::cout << "PIB (name): " << name << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Age: " << age << std::endl;
}