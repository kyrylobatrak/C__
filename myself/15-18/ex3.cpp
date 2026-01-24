#include <iostream>
#include <stdexcept>

using namespace std;

double division(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return static_cast<double>(a) / static_cast<double>(b);
}

int main() {
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    try {
       cout << division(a, b);
    }

    catch (const exception& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}