#include <iostream>
#include <string>
#include <numeric>
#include <cmath>
#include <stdexcept>

namespace MyCustomSpace {

    class Rational {
    private:
        int numerator;
        int denominator;

        void reduce() {
            int common_divisor = std::gcd(std::abs(numerator), denominator);
            numerator /= common_divisor;
            denominator /= common_divisor;

            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }

    public:
        Rational() : numerator(0), denominator(1) {}

        Rational(int num, int den) {
            if (den == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            numerator = num;
            denominator = den;
            reduce();
        }

        bool operator>(const Rational& other) const {
            return (numerator * other.denominator) > (other.numerator * denominator);
        }

        friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
            os << r.numerator << "/" << r.denominator;
            return os;
        }
    };

    template <typename T>
    T findMaximum(T a, T b) {
        return (a > b) ? a : b;
    }
}

int main() {
    using namespace MyCustomSpace;

    int i1 = 10;
    int i2 = 25;
    std::cout << "Max int: " << findMaximum(i1, i2) << std::endl;

    double d1 = 3.14;
    double d2 = 2.71;
    std::cout << "Max double: " << findMaximum(d1, d2) << std::endl;

    std::string s1 = "Apple";
    std::string s2 = "Banana";
    std::cout << "Max string: " << findMaximum(s1, s2) << std::endl;

    Rational r1(1, 2);
    Rational r2(3, 4);
    std::cout << "Max Rational: " << findMaximum(r1, r2) << std::endl;

    return 0;
}