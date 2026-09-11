#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string text = "hello world";

    std::transform(text.begin(), text.end(), text.begin(), ::toupper);

    std::cout << text << std::endl;

    return 0;
}