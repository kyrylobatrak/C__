#include "Rational17.1.h"
#include <iostream>
#include <cmath>
#include <iomanip> // For setprecision
#include <stdexcept>
#include <string>
#include <sstream>   // Для std::istringstream (тестування cin)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double SERIES_EPSILON = 0.01;
const double SERIES_TARGET_VALUE = (M_PI * M_PI) / 12.0;

void testRationalClass() {
    std::cout << "=================================================" << std::endl;
    std::cout << "Class 'Rational Number' (Overloaded Operators)" << std::endl;
    std::cout << "=================================================" << std::endl;

    try {
        Rational r1(1, 2);   // 1/2
        Rational r2(3, 4);   // 3/4
        Rational r3(4, -8);  // -1/2
        Rational r4(-10, 15); // -2/3

        std::cout << "--- Testing Initialization and Output (operator<<) ---" << std::endl;
        std::cout << "r1: " << r1 << std::endl;
        std::cout << "r2: " << r2 << std::endl;
        std::cout << "r3 (4/-8, reduced): " << r3 << std::endl;
        std::cout << "r4 (-10/15, reduced): " << r4 << std::endl;

        std::cout << "\n--- Testing Arithmetic Operators (r1=1/2, r2=3/4) ---" << std::endl;
        std::cout << "Sum (r1 + r2): " << (r1 + r2) << std::endl;         // 5/4
        std::cout << "Difference (r2 - r1): " << (r2 - r1) << std::endl; // 1/4
        std::cout << "Unary Minus (-r1): " << -r1 << std::endl;         // -1/2
        std::cout << "Product (r1 * r2): " << (r1 * r2) << std::endl;   // 3/8
        std::cout << "Quotient (r1 / r2): " << (r1 / r2) << std::endl;   // 2/3

    } catch (const std::invalid_argument& e) {
        std::cerr << "Rational Class Setup Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Exception Handling ---" << std::endl;

    try {
        std::cout << "Testing zero denominator in constructor (1/0)..." << std::endl;
        Rational bad_rational(1, 0);
        std::cout << "FAIL: Did not throw." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing division by zero (1/2 / 0/1)..." << std::endl;
        Rational r1(1, 2);
        Rational zero(0, 1);
        Rational result = r1 / zero;
        std::cout << "FAIL: Did not throw." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing input with zero denominator (simulating '1/0')..." << std::endl;
        std::istringstream iss("1/0");
        Rational r_in;
        iss >> r_in;
        std::cout << "FAIL: Did not throw." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected input exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing invalid file write (e.g., to '/invalid_path/test.txt')..." << std::endl;
        Rational r_file(3, 5);
        writeRationalToFile("/invalid_directory_path_123/test.txt", r_file);
        std::cout << "FAIL: Did not throw." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught expected file exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Testing valid file write to 'rational_out.txt'..." << std::endl;
        Rational r_file(7, 8);
        writeRationalToFile("rational_out.txt", r_file);
        std::cout << "Successfully wrote 7/8 to 'rational_out.txt'." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught unexpected file exception: " << e.what() << std::endl;
    }
}

void calculateSeriesSum() {
    std::cout << "\n\n=================================================" << std::endl;
    std::cout << "Series Sum Calculation (Pi^2 / 12)" << std::endl;
    std::cout << "=================================================" << std::endl;

    double sum = 0.0;
    double term = 0.0;
    int n = 1;

    std::cout << "Target Accuracy (Epsilon): " << SERIES_EPSILON << std::endl;

    do {
        double sign = (n % 2 == 1) ? 1.0 : -1.0;
        term = sign * (1.0 / (double)n / n);

        if (std::abs(term) < SERIES_EPSILON) {
            break;
        }

        sum += term;
        n++;
    } while (true);

    std::cout << "\n--- Calculation Results ---" << std::endl;
    std::cout << "Number of Terms Calculated (N): " << n - 1 << std::endl;
    std::cout << "Calculated Series Sum (S_N): " << std::fixed << std::setprecision(4) << sum << std::endl;

    double difference = std::abs(sum - SERIES_TARGET_VALUE);

    std::cout << "\n--- Convergence Check ---" << std::endl;
    std::cout << "Reference Value Pi^2 / 12: " << std::fixed << std::setprecision(4) << SERIES_TARGET_VALUE << std::endl;
    std::cout << "Difference |S_N - Target|: " << std::fixed << std::setprecision(6) << difference << std::endl;

    if (difference < SERIES_EPSILON) {
        std::cout << "CONCLUSION: The series converges to Pi^2 / 12 with accuracy " << SERIES_EPSILON << "." << std::endl;
    } else {
        std::cout << "CONCLUSION: The difference is greater than or equal to the specified accuracy." << std::endl;
    }
}


int main() {
    testRationalClass();
    calculateSeriesSum();
    return 0;
}