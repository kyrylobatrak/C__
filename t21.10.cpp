#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Person {
    std::string surname;
    int age;
};

void print_list(const std::string& title, const std::vector<Person>& people) {
    std::cout << "--- " << title << " ---" << std::endl;
    std::cout << std::left << std::setw(15) << "Surname" << "Age" << std::endl;
    for (const auto& p : people) {
        std::cout << std::left << std::setw(15) << p.surname << p.age << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Person> recruits = {
        {"Smith", 45}, {"Bond", 32}, {"Doe", 25},
        {"Ivanov", 19}, {"Petrov", 34}, {"Connor", 40},
        {"Ripley", 29}, {"Anderson", 36}, {"Neo", 22},
        {"Morpheus", 50}, {"Trinity", 30}, {"Yoda", 900}
    };

    print_list("Original List", recruits);

    auto partition_point = std::partition(recruits.begin(), recruits.end(), [](const Person& p) {
        return p.age < 35;
    });

    std::sort(recruits.begin(), partition_point, [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    std::sort(partition_point, recruits.end(), [](const Person& a, const Person& b) {
        return a.surname < b.surname;
    });

    print_list("Processed List (Recruits < 35 first)", recruits);

    return 0;
}