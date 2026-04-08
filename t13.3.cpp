#include <iostream>
#include <string>

std::string transformWords(const std::string& input) {

    std::string result = "";

    size_t pos = 0;

    while (pos < input.length()) {
        size_t wordStart = input.find_first_not_of(' ', pos);
        if (wordStart == std::string::npos) {
            result.append(input.substr(pos));
            break;
        }

        result.append(input.substr(pos, wordStart - pos));
        size_t wordEnd = input.find_first_of(' ', wordStart);

        if (wordEnd == std::string::npos) {
            size_t length = input.length() - wordStart;

            if (length > 0) {
                result.append(input.substr(wordStart, length - 1));
            }
            break;
        }

        size_t length = wordEnd - wordStart;

        if (length > 0) {
            result.append(input.substr(wordStart, length - 1));
        }
        pos = wordEnd;
    }
    return result;
}

int main() {

    std::string userInput;

    std::cout << "Enter string (latin, space-separated): ";

    std::getline(std::cin, userInput);

    std::string transformedResult = transformWords(userInput);

    std::cout << "Transformed: \"" << transformedResult << "\"" << std::endl;

    return 0;
}