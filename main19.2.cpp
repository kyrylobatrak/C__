#include <iostream>
#include <iomanip>
#include "vector19.2.h"

int main() {

    int d, n;

    std::cout << "Enter size (d): ";
    if (!(std::cin >> d) || d <= 0) {
        std::cerr << "Size must be a natural num!" << std::endl;
        return 1;
    }

    std::cout << "Enter count of vectors (n): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Cout of vectors must be natural num!" << std::endl;
        return 1;
    }

    Matrix my_vectors = input_vectors(n, d);

    double result = sum_of_norms(my_vectors);

    std::cout << "\n--- Results ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Sum of norms of vectors: " << result << std::endl;

    return 0;
}