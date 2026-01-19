#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    constexpr int ROWS = 2;
    constexpr int COLS = 3;

    int A[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int AT[COLS][ROWS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            AT[j][i] = A[i][j];
        }
    }

    cout << "Transposed Matrix:\n";
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            cout << setw(3) << AT[i][j];
        }
        cout << endl;
    }

    return 0;
}