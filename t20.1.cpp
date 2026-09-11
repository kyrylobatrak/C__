#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }


    std::map<std::string, int> wordFrequency;
    std::string word;

    while (file >> word) {
        std::string cleanedWord;
        for (char c : word) {
            if (std::isalpha(static_cast<unsigned char>(c))) {
                cleanedWord += c;
            }
        }

        if (!cleanedWord.empty()) {
            wordFrequency[cleanedWord]++;
        }
    }

    file.close();

    std::cout << "\nWord Frequencies:\n" << std::endl;
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}