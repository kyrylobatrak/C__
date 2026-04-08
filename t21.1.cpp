#include "t21.1.h"
#include <stdexcept>

BoolVector::BoolVector() {}

BoolVector::BoolVector(size_t size) : bits(size, false) {}


BoolVector::BoolVector(const std::string& binaryString) {
    for (char c : binaryString) {
        if (c == '1') bits.push_back(true);
        else bits.push_back(false);
    }
}

BoolVector BoolVector::conjunction(const BoolVector& other) const {
    if (bits.size() != other.bits.size()) {
        throw std::invalid_argument("Vectors must have the same size for conjunction.");
    }

    BoolVector result(bits.size());
    for (size_t i = 0; i < bits.size(); ++i) {
        result.bits[i] = bits[i] && other.bits[i];
    }
    return result;
}

BoolVector BoolVector::disjunction(const BoolVector& other) const {
    if (bits.size() != other.bits.size()) {
        throw std::invalid_argument("Vectors must have the same size for disjunction.");
    }

    BoolVector result(bits.size());
    for (size_t i = 0; i < bits.size(); ++i) {
        result.bits[i] = bits[i] || other.bits[i];
    }
    return result;
}

BoolVector BoolVector::negation() const {
    BoolVector result(bits.size());
    for (size_t i = 0; i < bits.size(); ++i) {
        result.bits[i] = !bits[i];
    }
    return result;
}

size_t BoolVector::countOnes() const {
    size_t count = 0;
    for (bool bit : bits) {
        if (bit) count++;
    }
    return count;
}

size_t BoolVector::countZeros() const {
    size_t count = 0;
    for (bool bit : bits) {
        if (!bit) count++;
    }
    return count;
}

size_t BoolVector::getSize() const {
    return bits.size();
}

void BoolVector::print() const {
    for (bool bit : bits) {
        std::cout << (bit ? "1" : "0");
    }
    std::cout << std::endl;
}