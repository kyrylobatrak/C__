#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int group;
    double average_grade;
};

Student getStudent() {
    Student s;
    cout << "Name: ";
    cin >> s.name;
    cout << "Group: ";
    cin >> s.group;
    cout << "Rating: ";
    cin >> s.average_grade;
    return s;
}

const Student& getBestStudent(const vector<Student>& students) {
    int bestIndex = 0;
    for (size_t i = 1; i < students.size(); i++) {
        if (students[i].average_grade > students[bestIndex].average_grade) {
            bestIndex = i;
        }
    }
    return students[bestIndex];
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> group;

    for (int i = 0; i < n; i++) {
        cout << "\nStudent #" << i + 1 << endl;
        group.push_back(getStudent()); // Додаємо в кінець вектора
    }

    if (n > 0) {
        const Student& best = getBestStudent(group);

        cout << "\n--- Best Student ---" << endl;
        cout << "Name: " << best.name << endl;
        cout << "Rating: " << best.average_grade << endl;
    }

    return 0;
}