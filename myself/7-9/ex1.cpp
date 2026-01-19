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

    int* Source = new int[N];

    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = ";
        cin >> Source[i];
    }

    int countEven = 0;
    int countOdd = 0;

    for (int i = 0; i < N; i++) {
        if (Source[i] % 2 == 0) {
            countEven++;
        }
        else {
            countOdd++;
        }
    }

    int* Evens = new int[countEven];
    int* Odds = new int[countOdd];

    int j = 0; // even
    int k = 0; // odd

    for (int i = 0; i < N; i++) {
        if (Source[i] % 2 == 0) {
            Evens[j] = Source[i];
            j++;
        }
        else {
            Odds[k] = Source[i];
            k++;
        }
    }

    cout << "Elements in Evens: ";
    for (int j = 0; j < countEven; j++) {
        cout << Evens[j] << " ";
    }
    cout << endl;

    delete[] Evens;


    cout << "Elements in Odds: ";
    for (int k = 0; k < countOdd; k++) {
        cout << Odds[k] << " ";
    }
    cout << endl;

    delete[] Odds;

    delete[] Source;

    return 0;
}