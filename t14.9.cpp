#include <iostream>
#include <fstream>
#include <string>
#include <sstream>    // Для std::stringstream (для розбору рядків)
#include <random>     // Для генерації випадкових чисел (std::mt19937)
#include <iomanip>    // Для std::setprecision (форматування виводу відсотків)

const std::string FILENAME = "game_results.txt";

void play_game(std::ofstream& file, int num_questions) {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;

    file << name;

    std::random_device rd; // Джерело справжньої випадковості (апаратне)
    std::mt19937 gen(rd()); // Генератор Mersenne Twister, засіяний від rd
    std::uniform_int_distribution<> distrib(1, 20); // Діапазон від 1 до 20 включно

    std::cout << "Answer the questions:\n";

    for (int k = 0; k < num_questions; ++k) {
        int i = distrib(gen);
        int j = distrib(gen);
        int user_answer;

        std::cout << "Question " << (k + 1) << "/" << num_questions << ": "
                  << i << " x " << j << " = ? ";

        std::cin >> user_answer;

        file << " " << i << "x" << j << "=" << user_answer;
    }

    file << "\n";
    std::cout << "Thank you, " << name << "! Your results have been saved.\n";
}


void show_results(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::cout << "\n--- Game Results ---\n";

    std::string line;
    // Читаємо файл рядок за рядком
    while (std::getline(file, line)) {
        std::stringstream ss(line); // Створюємо потік для парсингу всього рядка
        std::string name;
        std::string problem_str; // Окрема задача, напр. "2x2=4"

        // Перше слово в рядку - це ім'я
        ss >> name;

        int total_questions = 0;
        int correct_answers = 0;

        while (ss >> problem_str) {
            int i, j, answer;
            char delim_x, delim_eq;

            // Використовуємо інший stringstream для розбору окремої задачі
            std::stringstream problem_parser(problem_str);

            if (problem_parser >> i >> delim_x >> j >> delim_eq >> answer
                && delim_x == 'x' && delim_eq == '=') {

                total_questions++;
                if (i * j == answer) {
                    correct_answers++;
                }
            }
        }


        if (total_questions > 0) {
            double percentage = (static_cast<double>(correct_answers) / total_questions) * 100.0;
            std::cout << "Player " << name << ": "
                      << correct_answers << " out of " << total_questions << " correct ("
                      << std::fixed << std::setprecision(2) << percentage << "%)\n";
        } else {
            std::cout << "Player " << name << ": No problem data found.\n";
        }
    }

    file.close();
}

int main() {
    int num_players;
    int num_questions;

    std::cout << "--- Multiplication Table Game ---\n";
    std::cout << "How many players will play this session? ";
    std::cin >> num_players;

    std::cout << "How many questions for each player (e.g., 5 or 10)? ";
    std::cin >> num_questions;

    // Відкриваємо файл у режимі доповнення (std::ios::app)
    // Нові дані будуть додані в кінець файлу, не стираючи старі
    std::ofstream outfile(FILENAME, std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Critical Error: Could not open " << FILENAME << " for writing.\n";
        return 1;
    }

    for (int i = 0; i < num_players; ++i) {
        std::cout << "\n--- Player " << (i + 1) << " ---\n";
        play_game(outfile, num_questions);
    }

    outfile.close();

    show_results(FILENAME);

    return 0;
}