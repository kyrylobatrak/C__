#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    cout << "Enter the string: ";
    // Використовуємо getline, щоб зчитати рядок РАЗОМ із пробілами
    // (звичайний cin >> s обрізав би все після першого пробілу)
    getline(cin, s);

    size_t first = s.find('.');
    size_t last = s.rfind('.');


    if (first == string::npos) {
        cout << "[No dots found. Removing leading spaces...]" << endl;

        size_t firstChar = s.find_first_not_of(' ');

        if (firstChar == string::npos) {
            s.clear(); // або s = "";
        } else {
            s.erase(0, firstChar);
        }
    }

    else if (first == last) {
        cout << "[One dot found. Removing everything before it...]" << endl;

        // Видаляємо від початку (0) стільки символів, який індекс у крапки.
        // Приклад: "abc.text", крапка на індексі 3. Видаляємо 3 символи ("abc").
        // Крапка залишиться першою.
        s.erase(0, first);
    }

    else {
        cout << "[Multiple dots found. Removing text between first and last...]" << endl;

        // Математика видалення:
        // Початок: first + 1 (щоб не видалити саму першу крапку)
        // Кількість: last - first - 1 (відстань між ними мінус один крок)

        // Перевірка, чи крапки не стоять поруч (наприклад "hello..world")
        // Бо якщо вони поруч, видаляти нічого не треба.
        if (last > first + 1) {
            s.erase(first + 1, last - first - 1);
        }
    }

    cout << "Result: " << s << endl;

    return 0;
}