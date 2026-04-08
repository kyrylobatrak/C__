#include <iostream>
#include <vector>
#include <iomanip>
#include "main19.1.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of customers: " << endl;
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input" << endl;
        return 1;
    };

    vector<double> t(n);
    cout << "Enter values of the customers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "t " << i + 1 << ": ";
        cin >> t[i];
    }

    QueueResult result = process_queue(t);

    cout << "---Reusult---" << endl;
    cout << fixed << setprecision(2);

    cout << "Time spent in system(c1, c2,...,cn)" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Customer " << i + 1 << ": " << t[i] << "min "  << endl;
    }

    cout << "-------------------" << endl;
    cout << "Customer requiring LEAST service time (min t_i): #"
    << result.min_service_idx << " (Time: " << t[result.min_service_idx - 1] << ")" << endl;

    cout << "-------------------" << endl;
    cout << "Customer requiring MOST service time (max t_i): #"
    << result.max_spent_idx<< "(Time: " << t[result.max_spent_idx - 1] << ")" << endl;

    return 0;
}

