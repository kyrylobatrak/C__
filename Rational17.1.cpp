#include "Rational17.1.h"
#include <cmath>
#include <stdexcept>
#include <fstream>

void Rational::reduce() {
    int common_divisor = std::gcd(std::abs(numerator), denominator);

    numerator /= common_divisor;
    denominator /= common_divisor;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

Rational::Rational(int num, int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    numerator = num;
    denominator = den;

    reduce();
}

Rational Rational::operator+(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator-(const Rational& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational& other) const {
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}


Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Divide by zero.");
    }

    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;
    return Rational(new_numerator, new_denominator);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int num, den;
    char slash; // Для зчитування символу '/'

    if (is >> num >> slash && slash == '/' && is >> den) {
        if (den == 0) {
            is.setstate(std::ios::failbit);
            throw std::invalid_argument("Input denominator cannot be zero.");
        }

        r = Rational(num, den);

    } else {
        is.setstate(std::ios::failbit);
    }
    return is;
}

void writeRationalToFile(const std::string& filename, const Rational& r) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Error: Could not open file for writing: " + filename);
    }
    outFile << r;

    outFile.close();
}