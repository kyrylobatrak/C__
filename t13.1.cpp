#include <iostream>
#include <string>

std::string findSubstringBetween(const std::string& input) {

    size_t colonPos = input.find(':');

    if (colonPos == std::string::npos) {
        return "";
    }

    size_t commaPos = input.find(',', colonPos + 1);

    if (commaPos == std::string::npos) {
        return input.substr(colonPos + 1);
    }

    size_t length = commaPos - (colonPos + 1);

    return input.substr(colonPos + 1, length);
}

int main() {

    std::string userInput;

    std::cout << "Enter your string: ";

    std::getline(std::cin, userInput);

    std::string result = findSubstringBetween(userInput);

    std::cout << "Result: \"" << result << "\"" << std::endl;

    return 0;
}