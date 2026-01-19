#include <iostream>

using namespace std;

int main() {
    unsigned int num;
    cout << "Enter a number: ";
    cin >> num;

    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }

    cout << sum;

    return 0;
}