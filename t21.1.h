#pragma once

#include <vector>
#include <string>
#include <iostream>


class BoolVector {
private:
    std::vector<bool> bits;

public:
    BoolVector();
    BoolVector(size_t size);
    BoolVector(const std::string& binaryString);

    BoolVector conjunction(const BoolVector& other) const;

    BoolVector disjunction(const BoolVector& other) const;

    BoolVector negation() const;

    size_t countOnes() const;  // Кількість одиниць
    size_t countZeros() const; // Кількість нулів

    size_t getSize() const;
    void print() const;
};
