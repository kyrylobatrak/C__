#include <iostream>
#include <fstream>   // Для роботи з файлами (ifstream, ofstream)
#include <string>    // Для std::string
#include <sstream>   // Для std::stringstream (для легкого парсингу рядків)
#include <random>    // Для генерації випадкових даних (краще ніж rand())
#include <ctime>     // Для ініціалізації генератора випадкових чисел
#include <cfloat>    // Для DBL_MAX (найбільше можливе значення double)

void createStudentFile(int N, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    // Налаштовуємо генератор випадкових чисел
    // Використовуємо час як "seed" (зерно) для справжньої випадковості
    std::mt19937 gen(static_cast<unsigned long>(std::time(nullptr)));
    std::uniform_int_distribution<> courseDist(1, 4); // Курс від 1 до 4
    std::uniform_int_distribution<> groupDist(101, 105); // Група від 101 до 105
    std::uniform_int_distribution<> gradeCountDist(3, 5); // 3-5 оцінок
    std::uniform_int_distribution<> gradeDist(1, 5); // Оцінки від 1 до 5

    std::cout << "Generating " << N << " students into " << filename << "..." << std::endl;

    // Генеруємо N рядків (студентів)
    for (int i = 1; i <= N; ++i) {
        std::string lastName = "Student_" + std::to_string(i);
        int course = courseDist(gen);
        int group = groupDist(gen);


        outFile << lastName << " " << course << " " << group << " ";

        int numGrades = gradeCountDist(gen);
        for (int j = 0; j < numGrades; ++j) {
            outFile << gradeDist(gen);
            // Додаємо кому, якщо це не остання оцінка
            if (j < numGrades - 1) {
                outFile << ",";
            }
        }
        outFile << "\n";
    }


    outFile.close();
    std::cout << "File generation complete." << std::endl;
}

int main() {
    const std::string filename = "students.txt";
    const int numStudentsToGenerate = 10;

    createStudentFile(numStudentsToGenerate, filename);


    std::cout << "\nStarting analysis to find student with the worst average..." << std::endl;

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return 1;
    }

    std::string worstStudentLastName = "";
    double minAverage = DBL_MAX; // Починаємо з максимально можливого середнього
    std::string line;

    // Читаємо файл по одному рядку за раз
    while (std::getline(inFile, line)) {
        if (line.empty()) continue; // Пропускаємо порожні рядки

        // Використовуємо stringstream для легкого "розбору" рядка
        std::stringstream ss(line);

        std::string lastName;
        int course, group;
        std::string gradesStr; // Сюди зчитаємо частину "1,5,3,4"

        // Зчитуємо перші три "слова" з рядка
        if (!(ss >> lastName >> course >> group)) {
            std::cerr << "Warning: Skipping malformed line (basic info): " << line << std::endl;
            continue;
        }

        // Зчитуємо решту рядка - це наші оцінки
        if (!(ss >> gradesStr)) {
            std::cerr << "Warning: No grades found for " << lastName << std::endl;
            continue;
        }

        // Тепер нам потрібно розібрати рядок "1,5,3,4"
        std::stringstream gradesSS(gradesStr);
        std::string singleGradeStr; // Сюди будемо класти "1", потім "5", і т.д.

        double sum = 0;
        int count = 0;

        // Читаємо з 'gradesSS' доки не зустрінемо кому ','
        while (std::getline(gradesSS, singleGradeStr, ',')) {
            try {
                // Конвертуємо рядок (напр. "5") в число (int)
                sum += std::stoi(singleGradeStr);
                count++;
            } catch (const std::invalid_argument& e) {
                // Ця помилка виникне, якщо оцінка записана не числом, напр. "1,A,3"
                std::cerr << "Warning: Invalid grade format '" << singleGradeStr << "' for " << lastName << std::endl;
            }
        }

        // Обчислюємо середній бал, якщо у студента є оцінки
        if (count > 0) {
            double average = sum / count;

            // Перевіряємо, чи цей середній бал *менший* (гірший) за поточний мінімум
            if (average < minAverage) {
                minAverage = average; // Оновлюємо мінімум
                worstStudentLastName = lastName; // Запам'ятовуємо прізвище
            }
        }
    }

    // Закриваємо файл
    inFile.close();


    if (worstStudentLastName.empty()) {
        std::cout << "\nNo students or valid grades found in the file." << std::endl;
    } else {
        std::cout << "\n--- Result ---" << std::endl;
        std::cout << "Student with the worst average score: " << worstStudentLastName << std::endl;
        std::cout << "Their average score: " << minAverage << std::endl;
    }

    return 0; // Успішне завершення
}