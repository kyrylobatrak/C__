#pragma once

#include <vector>

using Vector = std::vector<double>;
using Matrix = std::vector<Vector>;

Matrix input_vectors(int n, int d);

double calculate_norm(const Vector& v);

double sum_of_norms(const Matrix& vectors);