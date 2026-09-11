#include <iostream>
#include <list>
#include <vector>
#include <numeric>
#include <cmath>

class Rational {
private:
    int num;
    int den;

    void simplify() {
        if (den == 0) throw std::runtime_error("Division by zero");
        if (den < 0) { num = -num; den = -den; }
        int common = std::gcd(std::abs(num), den);
        num /= common;
        den /= common;
    }

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) { simplify(); }

    Rational operator+(const Rational& other) const {
        return Rational(num * other.den + other.num * den, den * other.den);
    }

    Rational operator*(const Rational& other) const {
        return Rational(num * other.num, den * other.den);
    }

    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        if (r.den == 1) os << r.num;
        else os << r.num << "/" << r.den;
        return os;
    }
};

template <typename T>
class Polynomial {
private:
    std::list<T> coeffs;

public:
    Polynomial() {}

    Polynomial(std::initializer_list<T> l) : coeffs(l) {}

    void add_coeff(T val) {
        coeffs.push_back(val);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial<T>& poly) {
        if (poly.coeffs.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        int power = 0;

        for (const auto& c : poly.coeffs) {
            if (!first) os << " + ";
            os << "(" << c << ")*x^" << power;
            first = false;
            power++;
        }
        return os;
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> result;
        auto it1 = coeffs.begin();
        auto it2 = other.coeffs.begin();

        while (it1 != coeffs.end() || it2 != other.coeffs.end()) {
            T val1 = (it1 != coeffs.end()) ? *it1 : T(0);
            T val2 = (it2 != other.coeffs.end()) ? *it2 : T(0);

            result.add_coeff(val1 + val2);

            if (it1 != coeffs.end()) ++it1;
            if (it2 != other.coeffs.end()) ++it2;
        }
        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        if (coeffs.empty() || other.coeffs.empty()) return Polynomial<T>();

        size_t res_size = coeffs.size() + other.coeffs.size() - 1;
        std::vector<T> temp_res(res_size, T(0));

        int i = 0;
        for (const auto& c1 : coeffs) {
            int j = 0;
            for (const auto& c2 : other.coeffs) {
                temp_res[i + j] = temp_res[i + j] + (c1 * c2);
                j++;
            }
            i++;
        }

        Polynomial<T> result;
        for (const auto& val : temp_res) {
            result.add_coeff(val);
        }
        return result;
    }

    T evaluate(T x) const {
        if (coeffs.empty()) return T(0);

        auto it = coeffs.rbegin();
        T result = *it; // Старший коефіцієнт
        ++it;

        while (it != coeffs.rend()) {
            result = result * x + (*it);
            ++it;
        }
        return result;
    }
};

int main() {
    std::cout << "--- Test 1: Integer Polynomials ---\n";
    Polynomial<int> p1 = {1, 2}; // 1 + 2x
    Polynomial<int> p2 = {3, 4}; // 3 + 4x

    std::cout << "P1(x) = " << p1 << "\n";
    std::cout << "P2(x) = " << p2 << "\n";

    Polynomial<int> pSum = p1 + p2;
    std::cout << "Sum: " << pSum << "\n"; // 4 + 6x

    Polynomial<int> pMult = p1 * p2;
    std::cout << "Mult: " << pMult << "\n"; // (1+2x)(3+4x) = 3 + 4x + 6x + 8x^2 = 3 + 10x + 8x^2

    int x_int = 2;
    std::cout << "Value of P1 at x=" << x_int << ": " << p1.evaluate(x_int) << "\n"; // 1 + 2*2 = 5

    std::cout << "\n";

    std::cout << "--- Test 2: Double Polynomials ---\n";
    Polynomial<double> d1 = {0.5, 1.5}; // 0.5 + 1.5x
    Polynomial<double> d2 = {1.0, 2.0}; // 1.0 + 2.0x

    std::cout << "Mult (Double): " << d1 * d2 << "\n";
    std::cout << "Evaluate d1 at x=2.5: " << d1.evaluate(2.5) << "\n"; // 0.5 + 1.5*2.5 = 0.5 + 3.75 = 4.25

    std::cout << "\n";

    std::cout << "--- Test 3: Rational Polynomials ---\n";
    // P_rat = (1/2) + (3/4)x
    Polynomial<Rational> r1;
    r1.add_coeff(Rational(1, 2));
    r1.add_coeff(Rational(3, 4));

    // P_rat2 = (1/1) + (1/2)x
    Polynomial<Rational> r2;
    r2.add_coeff(Rational(1, 1));
    r2.add_coeff(Rational(1, 2));

    std::cout << "R1(x) = " << r1 << "\n";
    std::cout << "R2(x) = " << r2 << "\n";

    Polynomial<Rational> rMult = r1 * r2;
    // Очікуємо: (1/2 + 3/4x)(1 + 1/2x) = 1/2 + 1/4x + 3/4x + 3/8x^2 = 1/2 + 1x + 3/8x^2
    std::cout << "Mult (Rational): " << rMult << "\n";

    Rational x_rat(2, 1); // x = 2
    std::cout << "Evaluate R1 at x=2: " << r1.evaluate(x_rat) << "\n";
    // 1/2 + (3/4)*2 = 1/2 + 3/2 = 4/2 = 2

    return 0;
}