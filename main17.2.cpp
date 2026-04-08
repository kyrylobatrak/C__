#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <limits>

#include "Person17.2.h"
#include "UniversityMember17.2.h"
#include "Student17.2.h"
#include "Teacher17.2.h"
#include "Aspirant17.2.h"

void clear_cin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "\n--- Main Menu ---" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Add Teacher" << std::endl;
    std::cout << "3. Add Aspirant" << std::endl;
    std::cout << "4. Print Full Info For All" << std::endl;
    std::cout << "5. Print VUZ For All (dynamic_cast demo)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Your choice: ";
}

int main() {
    std::vector<std::unique_ptr<Person>> people;

    int choice = -1;
    while (choice != 0) {
        printMenu();

        if (!(std::cin >> choice)) {
            std::cerr << "Error: Please enter a number." << std::endl;
            clear_cin();
            continue;
        }

        switch (choice) {
            case 1: {
                try {
                    auto student = std::make_unique<Student>();
                    student->input();
                    people.push_back(std::move(student));
                    std::cout << "Student added successfully." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "CREATION FAILED: " << e.what() << std::endl;
                    clear_cin();
                }
                break;
            }
            case 2: {
                try {
                    auto teacher = std::make_unique<Teacher>();
                    teacher->input();
                    people.push_back(std::move(teacher));
                    std::cout << "Teacher added successfully." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "CREATION FAILED: " << e.what() << std::endl;
                    clear_cin();
                }
                break;
            }
            case 3: {
                try {
                    auto aspirant = std::make_unique<Aspirant>();
                    aspirant->input();
                    people.push_back(std::move(aspirant));
                    std::cout << "Aspirant added successfully." << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "CREATION FAILED: " << e.what() << std::endl;
                    clear_cin();
                }
                break;
            }
            case 4: {
                std::cout << "\n--- List of All People ---" << std::endl;
                if (people.empty()) {
                    std::cout << "The list is empty." << std::endl;
                }
                for (const auto& person : people) {
                    person->print();
                    std::cout << "-------------------------" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "\n--- List of VUZs ---" << std::endl;
                if (people.empty()) {
                    std::cout << "The list is empty." << std::endl;
                }
                for (const auto& person_ptr : people) {
                    Person* p = person_ptr.get();

                    UniversityMember* um = dynamic_cast<UniversityMember*>(p);

                    std::cout << p->getPIB() << ": ";
                    if (um != nullptr) {
                        std::cout << "VUZ: " << um->getVUZ() << std::endl;
                    } else {
                        std::cout << "(Not a university member)" << std::endl;
                    }
                }
                break;
            }
            case 0: {
                std::cout << "Exiting program." << std::endl;
                break;
            }
            default: {
                std::cerr << "Error: Unknown command." << std::endl;
                clear_cin();
                break;
            }
        }
    }

    return 0;
}