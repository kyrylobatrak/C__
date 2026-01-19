#include <iostream>
#include <cmath>  // Потрібна для sqrt() та cbrt()

using namespace std;

int fillArray(int* arr, int max_size) {
    int count = 0;
    cout << "Вводьте числа (0 для завершення):\n";

    for (int i = 0; i < max_size; ++i) {
        int temp;
        cin >> temp;

        if (temp == 0) {
            break;
        }

        arr[i] = temp;
        count++;
    }

    return count;
}

int main() {
    const int CAPACITY = 100;

    int* arr = new int[CAPACITY];

    int size = fillArray(arr, CAPACITY);

    cout << "Введено елементів: " << size << endl;

    int squares_count = 0;
    int cubes_count = 0;

    for (int i = 0; i < size; ++i) {
        int num = arr[i];

        if (num >= 0) {
            int root = round(sqrt(num));
            if (root * root == num) {
                squares_count++;
            }
        }


        int root_c = round(cbrt(num));
        if (root_c * root_c * root_c == num) {
            cubes_count++;

        }
    }

    cout << "Кількість повних квадратів: " << squares_count << endl;
    cout << "Кількість повних кубів: " << cubes_count << endl;

    delete[] arr;

    return 0;
}