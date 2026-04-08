#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using Matrix = std::vector<std::list<int>>;

void printMatrix(const Matrix& matrix) {
    std::cout << "Current matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    int n, m;

    std::cout << "Enter count of rows (n < 100): ";
    std::cin >> n;
    std::cout << "Enter count of columns (m < 100): ";
    std::cin >> m;

    if (n <= 0 || m <= 0) {
        std::cerr << "Invalid size!" << std::endl;
        return 1;
    }

    Matrix matrix(n);

    std::cout << "Enter el of matrix (" << n << "x" << m << "):" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < m; ++j) {
            int val;
            std::cin >> val;
            matrix[i].push_back(val);
        }
    }

    std::cout << "\n--- Before sort ---\n";
    printMatrix(matrix);

    std::sort(matrix.begin(), matrix.end(), [](const std::list<int>& rowA, const std::list<int>& rowB) {

        int maxA = *std::max_element(rowA.begin(), rowA.end());

        int maxB = *std::max_element(rowB.begin(), rowB.end());

        return maxA > maxB;
    });

    std::cout << "--- After sort (by max el of row) ---\n";
    printMatrix(matrix);

    return 0;
}