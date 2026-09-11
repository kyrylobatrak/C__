#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

long long get_sum_of_k_largest(std::vector<int> data, int k) {
    if (k > data.size() || k <= 0) {
        return 0;
    }

    std::sort(data.begin(), data.end(), std::greater<int>());

    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += data[i];
    }

    return sum;
}

std::vector<int> get_k_smallest_elements(std::vector<int> data, int k) {
    if (k > data.size() || k <= 0) {
        return {};
    }

    std::sort(data.begin(), data.end());

    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(data[i]);
    }

    return result;
}

int main() {
    std::vector<int> numbers = {10, 5, 8, 20, 3, 15};
    int k = 3;

    long long sum = get_sum_of_k_largest(numbers, k);
    std::vector<int> smallest = get_k_smallest_elements(numbers, k);

    std::cout << "Sum of " << k << " largest: " << sum << std::endl;

    std::cout << "The " << k << " smallest elements: ";
    for (int num : smallest) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}