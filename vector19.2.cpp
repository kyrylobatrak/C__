#include "vector19.2.h"
#include <iostream>
#include <cmath>

Matrix input_vectors(int n, int d) {
    Matrix vectors(n, Vector(d));

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter " << d << " coordinates of vector №" << (i + 1) << ": ";
        for (int j = 0; j < d; ++j) {
            std::cin >> vectors[i][j];
        }
    }
    return vectors;
}

double calculate_norm(const Vector& v) {
    double sum_squares = 0.0;
    for (double coord : v) {
        sum_squares += coord * coord;
    }
    return std::sqrt(sum_squares);
}


double sum_of_norms(const Matrix& vectors) {
    double total_sum = 0.0;
    for (const auto& vec : vectors) {
        total_sum += calculate_norm(vec);
    }
    return total_sum;
}