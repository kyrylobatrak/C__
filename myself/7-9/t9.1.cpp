#include <iostream>

using namespace std;

int main () {
    int n;
    cout << "Enter a number (size): ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Size must be positive!" << endl;
        return 1;
    }

    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }

    cout << "Sum of squares: " << sum << endl;

    delete [] arr;

    return 0;
}