#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Enter a number (size): ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: Size must be positive!" << endl;
        return 1;
    }

    double* A = new double[N];

    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = ";
        cin >> A[i];
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    double average = sum / N;
    cout << "Average = " << average << endl;

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > average) {
            count++;
        }
    }
    cout << "New size B = " << count << endl;


    if (count > 0) {
        double* B = new double[count];

        int j = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] > average) {
                B[j] = A[i];
                j++;
            }
        }

        cout << "Elements in B: ";
        for (int i = 0; i < count; i++) {
            cout << B[i] << " ";
        }
        cout << endl;

        delete[] B;
    } else {
        cout << "No elements greater than average." << endl;
    }

    delete[] A;

    return 0;
}