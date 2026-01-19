#include <iostream>
#include <array>
#include <utility> // Для std::pair

using namespace std;

template <size_t N>
pair<int, int> count_even_and_odd(const array<int, N>& arr, int logical_size) {
    int even_cnt = 0;
    int odd_cnt = 0;

    for (int i = 0; i < logical_size; ++i) {
        if (arr[i] % 2 == 0) {
            even_cnt++;
        } else {
            odd_cnt++;
        }
    }

    return {even_cnt, odd_cnt};
}

int main() {
    constexpr int N = 50;
    array<int, N> arr;

    int actual_size = 0;

    cout << "Enter numbers(0 for stop): \n";

    for (int i = 0; i < N; ++i) {
        int temp;
        cout << "arr[" << i << "] = ";
        cin >> temp;

        if (temp == 0) {
            break;
        }

        arr[i] = temp;
        actual_size++;
    }

    pair<int, int> result = count_even_and_odd(arr, actual_size);

    cout << "Even: " << result.first << "\n";
    cout << "Odd: " << result.second << "\n";

    return 0;
}