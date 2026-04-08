#include <iostream>
#include <string>

std::string modifyString(const std::string& input) {

    size_t firstDotPos = input.find('.');
    size_t lastDotPos = input.rfind('.');

    if (firstDotPos == std::string::npos) {
        size_t firstNonSpace = input.find_first_not_of(' ');

        if (firstNonSpace == std::string::npos) {
            return "";
        } else {
            return input.substr(firstNonSpace);
        }
    }

    else if (firstDotPos == lastDotPos) {
        return input.substr(firstDotPos);
    }

    else {
        std::string result = input;
        size_t startErase = firstDotPos + 1;
        size_t length = lastDotPos - firstDotPos - 1;
        result.erase(startErase, length);

        return result;
    }
}

int main() {

    std::string userInput;

    std::cout << "Enter your string: ";

    std::getline(std::cin, userInput);

    std::string result = modifyString(userInput);

    std::cout << "Result: \"" << result << "\"" << std::endl;

    return 0;
}