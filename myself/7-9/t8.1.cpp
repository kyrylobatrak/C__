#include <iostream>
#include <iomanip> // Використовуємо для std::setw

using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int N, M;
    cout << "Enter N (new value): ";
    cin >> N;
    cout << "Enter M (value to find): ";
    cin >> M;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (A[i][j] == M) {
                A[i][j] = N;
            }
        }
    }

    cout << "\nResult Matrix:\n";
    // Вивід матриці
    for (int i = 0; i < 3; ++i) {       // Зовнішній цикл (рядки)
        for (int j = 0; j < 3; ++j) {   // Внутрішній цикл (стовпці)
            // setw(4) робить фіксовану ширину для кожного числа
            cout << setw(4) << A[i][j];
        }
        // !!! КРИТИЧНО ВАЖЛИВО !!!
        // Переходимо на новий рядок тільки коли вивели весь рядок (внутрішній цикл завершився)
        cout << endl;
    }

    return 0;
}