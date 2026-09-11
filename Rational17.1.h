#pragma once

#include <iostream>
#include <numeric> // Для std::gcd (з C++17)
#include <string>  // Для імені файлу

class Rational {
private:
    int numerator;
    int denominator;
    void reduce(); // Приватний метод для скорочення дробу

public:
    Rational() : numerator(0), denominator(1) {}
    Rational(int num, int den);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const; // Бінарний мінус (a - b)
    Rational operator-() const;                     // Унарний мінус (-a)
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    friend std::istream& operator>>(std::istream& is, Rational& r);

    friend void writeRationalToFile(const std::string& filename, const Rational& r);
};