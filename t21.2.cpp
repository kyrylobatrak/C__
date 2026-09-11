#include <iostream>
#include <list>
#include <algorithm>

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;


    std::list<int> numbers;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        numbers.push_back(val);
    }

    int X;
    std::cout << "Enter X: ";
    std::cin >> X;

    std::partition(numbers.begin(), numbers.end(), [X](int i) {
        return i <= X;
    });

    std::cout << "Reordered list: ";
    for (const auto& val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}