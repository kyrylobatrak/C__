#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

void analyzeSentence(const std::string& input) {

    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    size_t shortestLength = SIZE_MAX;

    std::vector<std::string> allShortest;

    size_t pos = 0;

    while (pos < input.length()) {
        size_t wordStart = input.find_first_of(alphabet, pos);

        if (wordStart == std::string::npos) {
            break;
        }

        size_t wordEnd = input.find_first_not_of(alphabet, wordStart);
        size_t currentLength;
        std::string currentWord;

        if (wordEnd == std::string::npos) {
            currentLength = input.length() - wordStart;
            currentWord = input.substr(wordStart);
            pos = input.length();

        } else {
            currentLength = wordEnd - wordStart;
            currentWord = input.substr(wordStart, currentLength);
            pos = wordEnd;

        }

        if (currentLength < shortestLength) {
            shortestLength = currentLength;
            allShortest.clear();
            allShortest.push_back(currentWord);
        } else if (currentLength == shortestLength) {
            allShortest.push_back(currentWord);

        }
    }


    if (allShortest.empty()) {
        std::cout << "No words found in the sentence." << std::endl;
    } else {
        std::cout << "--- Results ---" << std::endl;

        std::cout << "a) First shortest word: " << allShortest.front() << std::endl;

        std::cout << "b) Last shortest word:  " << allShortest.back() << std::endl;

        std::cout << "c) All shortest words:  ";
        for (const std::string& word : allShortest) {
            std::cout << "\"" << word << "\" ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string userInput;

    std::cout << "Enter a sentence: ";

    std::getline(std::cin, userInput);

    analyzeSentence(userInput);

    return 0;
}