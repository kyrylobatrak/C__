#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Data {
    int day;
    int month;
    int year;
};

struct Employee {
    string name;
    string surname;
    char sex;
    string role;

    Data birthDate;
};

Employee getEmployee() {
    Employee emp;
    cout << "Enter employee name: ";
    cin >> emp.name;
    cout << "Enter employee surname: ";
    cin >> emp.surname;
    cout << "Enter a sex('M'/'F'): ";
    cin >> emp.sex;
    cout << "Enter employee role: ";
    cin >> emp.role;
    cout << "Enter employee birth date(day, month, year): ";
    cin >> emp.birthDate.day >> emp.birthDate.month >> emp.birthDate.year;
    return emp;
}

void getBestRole(const vector<Employee>& employees) {
    string popular_role = "";
    int maxCount = 0;

    for (int i = 0; i < employees.size(); i++) {
        string currentRole = employees[i].role;
        int currentCount = 0;

        for (int j = 0; j < employees.size(); j++) {
            if (employees[j].role == currentRole) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            popular_role = currentRole;
        }
    }
    cout << "The most popular role: " << popular_role << endl;
    cout << "The amount of employees: " << maxCount << endl;
}

void getSameName(const vector<Employee>& employees) {
    bool found = false;

    for (int i = 0; i < employees.size(); i++) {
        for (int j = i + 1; j < employees.size(); j++) {
            if (employees[j].name == employees[i].name) {
                cout << employees[i].surname << " and " << employees[j].surname <<
                    " have the same name " << employees[i].name << " and ";

                found = true;
            }
        }
    }
    if (!found) {
        cout << "No employees with the same name";
    }
}

void getSurnamestaerletter(const vector<Employee>& employees) {
    bool found = false;
    char letter;
    cout << "Enter a letter: ";
    cin >> letter;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].surname[0] == letter) {
            cout << "Employees with letter " << letter << " have " << employees[i].surname << endl;
        }
    }
    if (!found) {
        cout << "No employees with letter " << letter << endl;
    }
}

void getOldestMale(const vector<Employee>& employees) {
    int oldestMaleIndex = -1;

    cout << "\n--- Task d) Oldest Male ---" << endl;

    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].sex == 'M') {

            if (oldestMaleIndex == -1) {
                oldestMaleIndex = i;
            }
            else {
                const Data& currentDate = employees[i].birthDate;
                const Data& bestDate = employees[oldestMaleIndex].birthDate;

                if (currentDate.year < bestDate.year) {
                    oldestMaleIndex = i;
                }
                else if (currentDate.year == bestDate.year && currentDate.month < bestDate.month) {
                    oldestMaleIndex = i;
                }
                else if (currentDate.year == bestDate.year && currentDate.month == bestDate.month && currentDate.day < bestDate.day) {
                    oldestMaleIndex = i;
                }
            }
        }
    }

    if (oldestMaleIndex != -1) {
        cout << "The oldest male is: " << employees[oldestMaleIndex].surname
             << " " << employees[oldestMaleIndex].name
             << " (Born: " << employees[oldestMaleIndex].birthDate.year << ")" << endl;
    } else {
        cout << "No men found in the list." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee> employees;

    for (int i = 0; i < n; i++) {
        cout << "\nEmployee #" << i + 1 << endl;
        employees.push_back(getEmployee());
    }

    if (n > 0) {
        getBestRole(employees);
        getSameName(employees);
        getSurnamestaerletter(employees);
        getOldestMale(employees);
    }

    return 0;
}