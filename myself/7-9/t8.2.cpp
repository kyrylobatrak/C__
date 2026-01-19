#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    constexpr int ROWS = 3;
    constexpr int COLS = 3;

    double A[ROWS][COLS] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    int i_input, j_input;
    double a;

    cout << "Enter i (row index 0-2): ";
    cin >> i_input;
    cout << "Enter j (col index 0-2): ";
    cin >> j_input;
    cout << "Enter a (new value): ";
    cin >> a;


    if (i_input >= 0 && i_input < ROWS && j_input >= 0 && j_input < COLS) {

        A[i_input][j_input] = a;

    } else {
        cout << "\nError: Index out of bounds! Nothing changed.\n";
    }

    cout << "\nResult Matrix:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(6) << fixed << setprecision(1) << A[i][j];
        }
        cout << endl;
    }

    return 0;
}