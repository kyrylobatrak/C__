#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter count of rows: ";
    cin >> rows;
    cout << "Enter count of columns: ";
    cin >> cols;


    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    cout << "\nMulti board (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }


    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    matrix = nullptr;

    return 0;
}