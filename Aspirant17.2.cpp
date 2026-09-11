#include "Aspirant17.2.h"
#include <iostream>
#include <stdexcept>
#include <limits>

Aspirant::Aspirant()
    : Person("No Name", "Not Specified", "0"),
      UniversityMember(),
      Student(),
      Teacher()
{}

Aspirant::Aspirant(const std::string& name, const std::string& gender, const std::string& age,
                   const std::string& vuz, int course, const std::string& group,
                   const std::string& position, double salary)
    : Person(name, gender, age),
      UniversityMember(name, gender, age, vuz),
      Student(name, gender, age, vuz, course, group),
      Teacher(name, gender, age, vuz, position, salary)
{}

Aspirant::~Aspirant() {
}

void Aspirant::input() {
    Student::input();

    std::cout << "Enter position (as Teacher): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, position);

    std::cout << "Enter salary (as Teacher): ";
    while (!(std::cin >> salary)) {
        std::cerr << "Error: Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter salary (as Teacher): ";
    }

    if (salary < 0) {
        throw std::invalid_argument("Error in input(): Salary cannot be negative.");
    }
}

void Aspirant::print() const {
    Student::print();

    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}