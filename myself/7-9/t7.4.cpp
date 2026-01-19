#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

int max_value(const array<int, 5>& arr) {
    auto it = max_element(arr.begin(), arr.end());
    return *it;
}

int main() {
    array<int, 5> arr;

    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Maximum of all elements: " << max_value(arr);
    return 0;
}