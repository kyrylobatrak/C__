#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

std::string remove_words_by_frequency(const std::string& input_text, int k) {
    std::stringstream ss(input_text);
    std::string word;
    std::vector<std::string> words;
    std::map<std::string, int> word_counts;

    while (ss >> word) {
        words.push_back(word);
        word_counts[word]++;
    }

    std::string result = "";
    bool first = true;

    for (const auto& w : words) {
        if (word_counts[w] != k) {
            if (!first) {
                result += " ";
            }
            result += w;
            first = false;
        }
    }

    return result;
}

int main() {
    std::string text = "apple banana apple orange kiwi orange";
    int k = 2;

    std::cout << "Original: " << text << std::endl;

    std::string filtered_text = remove_words_by_frequency(text, k);

    std::cout << "Filtered (remove words appearing " << k << " times): " << filtered_text << std::endl;

    return 0;
}