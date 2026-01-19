#include <iostream>

// а) натуральне число n непарне
bool isOdd(int n) {
    return (n % 2 != 0);
}

// б) остання цифра числа n — 5
bool endsWithFive(int n) {
    return (std::abs(n) % 10 == 5);
}

// в) ціле число n кратне натуральному числу m
bool isMultiple(int n, int m) {
    if (m == 0) return false; // Захист від ділення на 0
    return (n % m == 0);
}

// г) n i k одночасно кратні m
bool bothMultiple(int n, int k, int m) {
    if (m == 0) return false;
    return (n % m == 0) && (k % m == 0);
}

// д) сума першої і другої цифри двозначного числа - двозначне число
bool sumDigitsIsTwoDigit(int n) {
    if (n < 10 || n > 99) return false;

    int sum = (n / 10) + (n % 10);
    return (sum > 9);
}

// е) число x більше за число y не менше, ніж на 7
bool isGreaterBySeven(int x, int y) {
    return (x - y >= 7);
}

// 1) принаймні одне з чисел x, y або z більше за 99
bool atLeastOneBig(int x, int y, int z) {
    return (x > 99) || (y > 99) || (z > 99);
}

// ж) ТІЛЬКИ одне з чисел x, y або z менше за 1001

bool exactlyOneSmall(int x, int y, int z) {
    int count = 0;
    if (x < 1001) count++;
    if (y < 1001) count++;
    if (z < 1001) count++;

    return (count == 1);
}

int main() {

    int n = 25;
    int m = 5;

    std::cout << "Task a (is 25 odd?): " << isOdd(n) << "\n";      // Виведе 1
    std::cout << "Task b (ends with 5?): " << endsWithFive(n) << "\n"; // Виведе 1
    std::cout << "Task c (25 divisible by 5?): " << isMultiple(n, m) << "\n"; // Виведе 1
    std::cout << "Task zh (100, 2000, 3000): " << exactlyOneSmall(100, 2000, 3000) << "\n";
    std::cout << "Task zh (100, 100, 3000): " << exactlyOneSmall(100, 100, 3000) << "\n";

    return 0;
}