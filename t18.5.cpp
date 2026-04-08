#include <iostream>


template <typename T>
class Array {
private:
    T* data;
    size_t length;

public:
    Array(size_t size) : length(size) {
        data = new T[length];
    }

    ~Array() {
        delete[] data;
    }

    void set(size_t index, T value) {
        if (index < length) {
            data[index] = value;
        }
    }

    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    static void shakerSort(T* arr, size_t n) {
        if (n <= 1) return;

        bool swapped = true;
        size_t start = 0;
        size_t end = n - 1;

        while (swapped) {
            swapped = false;

            for (size_t i = start; i < end; ++i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped) break;

            swapped = false;
            end--;

            for (size_t i = end - 1; i >= start; --i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
                if (i == 0) break;
            }
            start++;
        }
    }

    void sort() {
        shakerSort(this->data, this->length);
    }
};

int main() {
    std::cout << "--- Test 1: Member Method Sort (Object) ---" << std::endl;
    Array<int> myArray(6);
    myArray.set(0, 45);
    myArray.set(1, 12);
    myArray.set(2, 89);
    myArray.set(3, 5);
    myArray.set(4, 23);
    myArray.set(5, 1);

    std::cout << "Original: ";
    myArray.print();

    myArray.sort();

    std::cout << "Sorted:   ";
    myArray.print();

    std::cout << "\n--- Test 2: Static Method Sort (Raw Array) ---" << std::endl;
    double rawArray[] = {3.14, 1.59, 2.65, 5.35, 0.11};
    size_t rawSize = 5;

    std::cout << "Original: ";
    for (size_t i = 0; i < rawSize; ++i) std::cout << rawArray[i] << " ";
    std::cout << std::endl;

    Array<double>::shakerSort(rawArray, rawSize);

    std::cout << "Sorted:   ";
    for (size_t i = 0; i < rawSize; ++i) std::cout << rawArray[i] << " ";
    std::cout << std::endl;

    return 0;
}