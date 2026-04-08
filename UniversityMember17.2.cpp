#include "UniversityMember17.2.h"
#include "Person17.2.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>


UniversityMember::UniversityMember()
    : Person("No Name", "Not Specified", "0"), VUZ("Unknown") {
}

UniversityMember::UniversityMember(const std::string& name, const std::string& gender, const std::string& age,
                                     const std::string& vuz)
    : Person(name, gender, age), VUZ(vuz) {

    if (vuz.empty()) {
        throw std::invalid_argument("Error in UniversityMember constructor: VUZ name cannot be empty.");
    }
}

UniversityMember::~UniversityMember() {
}

std::string UniversityMember::getVUZ() const {
    return this->VUZ;
}

void UniversityMember::input() {
    Person::input();

    std::cout << "Enter VUZ name: ";

    std::getline(std::cin, VUZ);

    if (VUZ.empty()) {
        throw std::invalid_argument("Error in input(): VUZ name cannot be empty.");
    }
}

void UniversityMember::print() const {
    Person::print();

    std::cout << "VUZ: " << VUZ << std::endl;
}
