#include <iostream>
#include <vector>
#include <iomanip> // Для гарного виводу (setw)
#include <algorithm> // Для std::swap

using namespace std;

int main() {
    int n, m;
    cout << "Введіть кількість рядків (N): ";
    cin >> n;
    cout << "Введіть кількість стовпців (M): ";
    cin >> m;

    vector<vector<int>> A(n, vector<int>(m));

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int min_val = A[0][0];
    int max_val = A[0][0];

    int min_row_index = 0;
    int max_row_index = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if (A[i][j] < min_val) {
                min_val = A[i][j];
                min_row_index = i; // Запам'ятовуємо номер рядка
            }

            if (A[i][j] > max_val) {
                max_val = A[i][j];
                max_row_index = i; // Запам'ятовуємо номер рядка
            }
        }
    }



    if (min_row_index != max_row_index) {

        for (int j = 0; j < m; ++j) {
            std::swap(A[min_row_index][j], A[max_row_index][j]);
        }
        cout << "\nРядки успішно поміняні місцями!\n";
    } else {
        cout << "\nМінімум і максимум в одному рядку. Обмін не потрібен.\n";
    }

    cout << "\nРезультат:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }

    return 0;
}