#include <iostream>
#include <fstream>  // Для роботи з файлами (input/output file stream)
#include <string>   // Для використання std::string
#include <cctype>   // Для функції toupper (перетворення в верхній регістр)

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    std::ifstream inFile(inputFilename); // Читання
    std::ofstream outFile(outputFilename); // Запис

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFilename << std::endl;
        return 1; //
    }
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open output file: " << outputFilename << std::endl;
        inFile.close();
        return 1;
    }

    std::string word;
    bool capitalizeNext = false; // Прапорець, який вказує, чи треба капіталізувати наступне слово

    // Читаємо перше слово окремо, щоб коректно обробити пробіли
    if (inFile >> word) {
        outFile << word;

        if (word == "die" || word == "der" || word == "das") {
            capitalizeNext = true; // Якщо так, встановлюємо прапорець
        }
    } else {
        std::cout << "Input file is empty." << std::endl;
        inFile.close();
        outFile.close();
        return 0;
    }

    // Читаємо решту файлу по одному слову за раз
    while (inFile >> word) {

        // Перевіряємо, чи встановлено прапорець з попередньої ітерації
        if (capitalizeNext) {
            // Перевіряємо, чи слово не порожнє (про всяк випадок)
            if (!word.empty()) {
                // Замінюємо перший символ слова на його версію у верхньому регістрі
                word[0] = std::toupper(word[0]);
            }
            // Скидаємо прапорець, оскільки ми виконали завдання
            capitalizeNext = false;
        }

        // Записуємо пробіл ПЕРЕД наступним словом
        outFile << " ";
        // Записуємо поточне (можливо, змінене) слово
        outFile << word;

        if (word == "die" || word == "der" || word == "das") {
            capitalizeNext = true;
        }
    }

    inFile.close();
    outFile.close();

    std::cout << "File has been processed successfully. Check " << outputFilename << std::endl;

    return 0;
}