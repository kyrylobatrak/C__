#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    long long res = 1;

    while (res <= n) {
        res *= 2;
    }

    std::cout << res << "\n";

    return 0;
}