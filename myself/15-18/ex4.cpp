#include <iostream>
#include <string>

using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    cout << "Int Before: " << num1 << " | " << num2 << endl;

    mySwap(num1, num2);

    cout << "Int After:  " << num1 << " | " << num2 << endl;

    cout << "-----------------" << endl;

    string s1 = "Hello";
    string s2 = "World";

    cout << "String Before: " << s1 << " | " << s2 << endl;

    mySwap(s1, s2);

    cout << "String After:  " << s1 << " | " << s2 << endl;

    return 0;
}