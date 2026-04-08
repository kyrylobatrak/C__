#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Sum {
public:
    T total;

    Sum() : total(0) {}

    void operator()(T element) {
        total += element;
    }
};

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    Sum<int> result = std::for_each(numbers.begin(), numbers.end(), Sum<int>());

    std::cout << "Sum of elements: " << result.total << std::endl;

    std::vector<double> decimals = {1.5, 2.5, 3.5};
    Sum<double> result_decimals = std::for_each(decimals.begin(), decimals.end(), Sum<double>());

    std::cout << "Sum of decimals: " << result_decimals.total << std::endl;

    return 0;
}