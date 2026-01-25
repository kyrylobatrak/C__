#include <iostream>
#include <vector>
#include <algorithm> // для sort, remove_if, transform
#include <numeric>   // для accumulate

using namespace std;

struct Calibrator {
    double operator()(double x) {
        return x * 2.5 + 10.0;
    }
};

int main() {
    vector<double> signal = {10.5, -5.0, 0.0, 100.0, 23.4, -1.0, 50.2, 12.0};

    cout << "Original size: " << signal.size() << endl;

    signal.erase(
        remove_if(signal.begin(), signal.end(), [](double x) {
            return x < 0;
        }),
        signal.end()
    );

    cout << "Filtered size: " << signal.size() << endl;

    vector<double> processed;
    processed.resize(signal.size());

    transform(signal.begin(), signal.end(), processed.begin(), Calibrator());

    cout << "Processed data: ";
    for (double x : processed) cout << x << " ";
    cout << endl;

    sort(processed.begin(), processed.end(), [](double a, double b) {
        return a > b;
    });

    cout << "Top signal (Max): " << processed[0] << endl;

    double energy = accumulate(processed.begin(), processed.end(), 0.0, [](double currentSum, double val) {
        return currentSum + val * val;
    });

    cout << "Signal Energy: " << energy << endl;

    return 0;
}