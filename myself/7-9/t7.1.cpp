#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};

    int n;
    cout << "Enter n: ";
    cin >> n;

    short count = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] < n) {
            count++;
        }
    }

    cout << count;

    return 0;
}