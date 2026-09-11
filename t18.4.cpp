#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T>
class Mediana {
private:
    T data[100];
    int current_size;

public:
    Mediana() : current_size(0) {}

    Mediana(T* arr, int size) {
        if (size > 100) {
            throw std::overflow_error("Array size exceeds limit of 100");
        }
        current_size = size;
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    void push(T element) {
        if (current_size >= 100) {
            throw std::overflow_error("Container is full");
        }
        data[current_size++] = element;
    }

    T pop(int n) {
        if (n < 0 || n >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        T val = data[n];
        for (int i = n; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        current_size--;
        return val;
    }

    T mediana() {
        if (current_size == 0) {
            throw std::runtime_error("Container is empty");
        }
        std::vector<T> temp(data, data + current_size);
        std::sort(temp.begin(), temp.end());

        if (current_size % 2 != 0) {
            return temp[current_size / 2];
        } else {
            return (temp[current_size / 2 - 1] + temp[current_size / 2]) / 2;
        }
    }

    int getSize() const {
        return current_size;
    }
};

int main() {
    try {
        Mediana<double> m1;
        m1.push(5.0);
        m1.push(2.0);
        m1.push(9.0);
        m1.push(1.0);
        m1.push(7.0);

        std::cout << "Current size: " << m1.getSize() << std::endl;
        std::cout << "Median: " << m1.mediana() << std::endl;

        std::cout << "Popped element at index 2: " << m1.pop(2) << std::endl;

        std::cout << "New median: " << m1.mediana() << std::endl;

        double arr[] = {10.5, 20.1, 30.2, 40.8};
        Mediana<double> m2(arr, 4);
        std::cout << "Median from array constructor: " << m2.mediana() << std::endl;

        m2.pop(10);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}