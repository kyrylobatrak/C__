#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iomanip>

class PolynomialInputException : public std::runtime_error {
public:
    PolynomialInputException(const std::string& message)
        : std::runtime_error(message) {}
};

class Polynomial {
private:
    int degree;
    std::vector<double> coefficients;

    void normalize() {
        int newDegree = coefficients.size() - 1;

        while (newDegree > 0 && coefficients[newDegree] == 0.0) {
            newDegree--;
        }

        if (coefficients.size() == 1 && coefficients[0] == 0.0) {
            newDegree = 0;
        }

        if (newDegree != degree || (coefficients.size() > newDegree + 1)) {
            degree = newDegree;
            coefficients.resize(degree + 1);
        }

        if (coefficients.empty()) {
            degree = 0;
            coefficients.push_back(0.0);
        }
    }

public:
    Polynomial() : degree(0) {
        coefficients.push_back(0.0);
    }

    Polynomial(int deg, const std::vector<double>& coeffs) {
        if (deg < 0) {
            throw PolynomialInputException("Degree cannot be negative.");
        }
        if (coeffs.size() != static_cast<size_t>(deg + 1)) {
            throw PolynomialInputException("Coefficient count mismatch for the given degree.");
        }
        degree = deg;
        coefficients = coeffs;
        normalize();
    }

    void readFromString(const std::string& input) {
        std::stringstream ss(input);
        int newDegree;
        ss >> newDegree;

        if (ss.fail() || newDegree < 0) {
            throw PolynomialInputException("Invalid degree input from string.");
        }

        std::vector<double> newCoeffs;
        double coeff;
        while (ss >> coeff) {
            newCoeffs.push_back(coeff);
        }

        if (ss.fail() && !ss.eof()) {
            throw PolynomialInputException("Invalid coefficient input. Not a real number.");
        }

        if (newCoeffs.size() != static_cast<size_t>(newDegree + 1)) {
            throw PolynomialInputException("Degree and coefficient count mismatch in string.");
        }

        this->degree = newDegree;
        this->coefficients = newCoeffs;
        normalize();
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = degree; i >= 0; --i) {
            result = result * x + coefficients[i];
        }
        return result;
    }

    Polynomial derivative() const {
        if (degree == 0) {
            return Polynomial();
        }
        int newDegree = degree - 1;
        std::vector<double> newCoeffs(newDegree + 1);
        for (int i = 0; i <= newDegree; ++i) {
            newCoeffs[i] = coefficients[i + 1] * (i + 1);
        }
        return Polynomial(newDegree, newCoeffs);
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(this->degree, other.degree);
        std::vector<double> newCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= this->degree; ++i) {
            newCoeffs[i] += this->coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] += other.coefficients[i];
        }
        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(this->degree, other.degree);
        std::vector<double> newCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= this->degree; ++i) {
            newCoeffs[i] += this->coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] -= other.coefficients[i];
        }
        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial operator*(const Polynomial& other) const {
        int newDegree = this->degree + other.degree;
        std::vector<double> newCoeffs(newDegree + 1, 0.0);

        for (int i = 0; i <= this->degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += this->coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(newDegree, newCoeffs);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.degree == 0 && p.coefficients[0] == 0.0) {
            os << "0";
            return os;
        }

        bool firstTerm = true;
        os << std::setprecision(4);

        for (int i = p.degree; i >= 0; --i) {
            double coeff = p.coefficients[i];
            if (coeff == 0.0) continue;

            double absCoeff = std::abs(coeff);

            if (!firstTerm) {
                os << (coeff > 0 ? " + " : " - ");
            } else if (coeff < 0) {
                os << "-";
            }

            if (absCoeff != 1.0 || i == 0) {
                os << absCoeff;
            }

            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            firstTerm = false;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Polynomial& p) {
        int newDegree;
        std::cout << "Enter degree: ";
        if (!(is >> newDegree) || newDegree < 0) {
            is.clear();
            is.ignore(10000, '\n');
            throw PolynomialInputException("Invalid degree. Must be non-negative integer.");
        }

        std::vector<double> newCoeffs(newDegree + 1);
        std::cout << "Enter " << newDegree + 1 << " coefficients (from c0 to c" << newDegree << "): ";
        for (int i = 0; i <= newDegree; ++i) {
            if (!(is >> newCoeffs[i])) {
                is.clear();
                is.ignore(10000, '\n');
                throw PolynomialInputException("Invalid coefficient. Must be a real number.");
            }
        }

        p = Polynomial(newDegree, newCoeffs);
        return is;
    }
};

int main() {
    std::cout << "--- Error Handling Demonstration ---" << std::endl;

    try {
        std::cout << "\nTest 1: Entering negative degree..." << std::endl;
        Polynomial p_err1;
        std::cin >> p_err1;
    } catch (const PolynomialInputException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 2: Entering invalid coefficient..." << std::endl;
        Polynomial p_err2;
        std::cin >> p_err2;
    } catch (const PolynomialInputException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 3: Parsing string with invalid degree '-2'..." << std::endl;
        Polynomial p_err3;
        p_err3.readFromString("-2 1.0 2.0");
        std::cout << "Parsed: " << p_err3 << std::endl;
    } catch (const PolynomialInputException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 4: Parsing string with invalid coefficient 'hello'..." << std::endl;
        Polynomial p_err4;
        p_err4.readFromString("2 1.0 2.0 hello");
        std::cout << "Parsed: " << p_err4 << std::endl;
    } catch (const PolynomialInputException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 5: Parsing string with coefficient count mismatch..." << std::endl;
        Polynomial p_err5;
        p_err5.readFromString("3 1.0 2.0");
        std::cout << "Parsed: " << p_err5 << std::endl;
    } catch (const PolynomialInputException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Feature Demonstration ---" << std::endl;

    try {
        Polynomial p1;
        std::cout << "\nEnter Polynomial P1." << std::endl;
        std::cin >> p1;
        std::cout << "P1(x) = " << p1 << std::endl;

        Polynomial p2;
        std::string p2_str = "2 4.0 0.0 1.0";
        std::cout << "\nEntering P2(x) from string '" << p2_str << "'" << std::endl;
        p2.readFromString(p2_str);
        std::cout << "P2(x) = " << p2 << std::endl;

        double x = 2.0;
        std::cout << "\nEvaluating P1 at x = " << x << ": " << p1.evaluate(x) << std::endl;
        std::cout << "Evaluating P2 at x = " << x << ": " << p2.evaluate(x) << std::endl;

        Polynomial p1_deriv = p1.derivative();
        std::cout << "\nDerivative of P1: P1'(x) = " << p1_deriv << std::endl;

        Polynomial p2_deriv = p2.derivative();
        std::cout << "Derivative of P2: P2'(x) = " << p2_deriv << std::endl;

        Polynomial p_sum = p1 + p2;
        std::cout << "\nSum (P1 + P2): " << p_sum << std::endl;

        Polynomial p_diff = p1 - p2;
        std::cout << "\nDifference (P1 - P2): " << p_diff << std::endl;

        Polynomial p_prod = p1 * p2;
        std::cout << "\nProduct (P1 * P2): " << p_prod << std::endl;

        Polynomial p_zero_test(2, {0.0, 0.0, 0.0});
        std::cout << "\nZero polynomial test (0x^2 + 0x + 0): " << p_zero_test << std::endl;

    } catch (const PolynomialInputException& e) {
        std::cout << "An unexpected error occurred during feature demo: " << e.what() << std::endl;
    }

    return 0;
}