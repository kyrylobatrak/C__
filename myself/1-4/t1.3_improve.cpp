#include <iostream>


using namespace std;

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    int N;
    cout << "Enter a count: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cout << " - " << a;
    }


    return 0;
}