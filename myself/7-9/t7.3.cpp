#include <iostream>
#include <array>
#include <cmath> // Для константи M_E (число e)


template <std::size_t N>
double sum_greater_than_e(const std::array<double, N>& arr) {
    const double e = 2.718281828;

    double sum = 0.0;

    for (const auto& x : arr) {
        if (x > e) {
            sum += x;
        }
    }
    return sum;
}

int main() {
    constexpr int N = 10;

    std::array<double, N> arr;

    std::cout << "Введіть " << N << " дійсних чисел:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    double result = sum_greater_than_e(arr);

    std::cout << "Сума елементів > e: " << result << std::endl;

    return 0;
}