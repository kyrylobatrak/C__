#include <iostream>
#include "t21.1.h"

int main() {
    try {
        std::cout << "Creating vectors..." << std::endl;
        BoolVector v1("10110");
        BoolVector v2("01100");


        std::cout << "Vector 1: "; v1.print();
        std::cout << "Vector 2: "; v2.print();
        std::cout << "------------------------" << std::endl;

        BoolVector vAnd = v1.conjunction(v2);
        std::cout << "Conjunction (AND): ";
        vAnd.print();

        BoolVector vOr = v1.disjunction(v2);
        std::cout << "Disjunction (OR):  ";
        vOr.print();

        BoolVector vNot = v1.negation();
        std::cout << "Negation (NOT v1): ";
        vNot.print();

        std::cout << "------------------------" << std::endl;


        std::cout << "Stats for Vector 1 (10110):" << std::endl;
        std::cout << "Number of Ones:  " << v1.countOnes() << std::endl;
        std::cout << "Number of Zeros: " << v1.countZeros() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}