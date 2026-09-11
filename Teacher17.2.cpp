#include "Teacher17.2.h"
#include <iostream>
#include <stdexcept>
#include <limits>

Teacher::Teacher()
    : Person("No Name", "Not Specified", "0"),
      UniversityMember(),
      position("Unknown"),
      salary(0.0)
{}

Teacher::Teacher(const std::string& name, const std::string& gender, const std::string& age,
                 const std::string& vuz, const std::string& pos, double sal)
    : Person(name, gender, age),
      UniversityMember(name, gender, age, vuz),
      position(pos),
      salary(sal)
{
    if (salary < 0) {
        throw std::invalid_argument("Error in Teacher constructor: Salary cannot be negative.");
    }
}

Teacher::~Teacher() {
}

void Teacher::input() {
    UniversityMember::input();

    std::cout << "Enter position: ";
    std::getline(std::cin, position);

    std::cout << "Enter salary: ";
    while (!(std::cin >> salary)) {
        std::cerr << "Error: Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter salary: ";
    }

    if (salary < 0) {
        throw std::invalid_argument("Error in input(): Salary cannot be negative.");
    }
}

void Teacher::print() const {
    UniversityMember::print();

    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}