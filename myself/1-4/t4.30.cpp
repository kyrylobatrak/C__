#include <iostream>
#include <numeric>

int eulerPhiNaive(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (std::gcd(i, n) == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "phi(" << n << ") = " << eulerPhiNaive(n) << "\n";
    return 0;
}