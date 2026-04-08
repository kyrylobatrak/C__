#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "expression.txt";

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erorr: impossible open file " << filename << std::endl;
        return 1;
    }

    double result = 0.0;
    double currentNumber;
    char operation;

    // 1. Читаємо перше число
    if (!(file >> result)) {
        std::cerr << "Error: The file is empty or in the wrong format " << std::endl;
        file.close();
        return 1;
    }

    // 2. Читаємо оператори та наступні числа в циклі
    // Цикл триває, доки ми можемо зчитати оператор і цей оператор не '='
    while (file >> operation && operation != '=') {

        // Після оператора має йти число
        if (!(file >> currentNumber)) {
            std::cerr << "Error: The number after the operator was expected '" << operation << "'" << std::endl;
            file.close();
            return 1;
        }

        // Виконуємо дію
        if (operation == '+') {
            result += currentNumber;
        } else if (operation == '-') {
            result -= currentNumber;
        } else {
            // Якщо оператор не '+' або '-' (і не '='), то формат невірний
            std::cerr << "Error: Unknown operator '" << operation << "'" << std::endl;
            file.close();
            return 1;
        }
    }

    file.close();

    std::cout << "Result of the calculation: " << result << std::endl;

    return 0;
}