#include "Student17.2.h"
#include <iostream>
#include <stdexcept>
#include <limits>

Student::Student()
    : Person("No Name", "Not Specified", "0"),
      UniversityMember(),
      course(1),
      group("Unknown")
{}

Student::Student(const std::string& name, const std::string& gender, const std::string& age,
                 const std::string& vuz, int c, const std::string& g)
    : Person(name, gender, age),
      UniversityMember(name, gender, age, vuz),
      course(c),
      group(g)
{
    if (course < 1 || course > 7) {
        throw std::invalid_argument("Error in Student constructor: Invalid course.");
    }
}

Student::~Student() {
}

void Student::input() {
    UniversityMember::input();

    std::cout << "Enter course (1-6): ";
    while (!(std::cin >> course)) {
        std::cerr << "Error: Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter course (1-6): ";
    }

    if (course < 1 || course > 7) {
        throw std::invalid_argument("Error in input(): Invalid course.");
    }

    std::cout << "Enter group: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, group);
}

void Student::print() const {
    UniversityMember::print();

    std::cout << "Course: " << course << std::endl;
    std::cout << "Group: " << group << std::endl;
}