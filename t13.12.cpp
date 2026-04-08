#include <iostream>
#include <string>
#include <cctype>

std::string capitalizeWords(const std::string& input) {

    std::string result = input;
    bool isStartOfWord = true;

    for (size_t i = 0; i < result.length(); ++i) {
        unsigned char c = result[i];
        if (std::isalpha(c)) {
            if (isStartOfWord) {
                result[i] = std::toupper(c);
                isStartOfWord = false;
            }
        } else {
            isStartOfWord = true;
        }
    }
    return result;
}

int main() {
    std::string userInput;

    std::cout << "Enter a sentence: ";

    std::getline(std::cin, userInput);

    std::string capitalizedResult = capitalizeWords(userInput);

    std::cout << "Capitalized: \"" << capitalizedResult << "\"" << std::endl;

    return 0;
}