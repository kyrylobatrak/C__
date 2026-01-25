#include <iostream>
#include <string>
#include <cmath>


using namespace std;

namespace Science {
    namespace Math {
        int pow(int base, int ex) {
            int result = 1;
            for (int i = 0; i < ex; i++) {
                result *= base;
            }
            cout << "My custom pow used: " << result << endl;
            return result;
        }
    }

    template <typename T>
    class Element {
    private:
        T value;
    public:
        Element(T v) {
            value = v;
        }

        T getValue() {
            return value;
        }

        void print() {
            cout << "Element value: " << value << endl;
        }
    };
}

template <typename T> void compareElements(Science::Element<T> a,Science::Element<T> b) {
    if (a.getValue() == b.getValue()) {
        cout << "equal: " << a.getValue() << endl;
    }
    else if (a.getValue() > b.getValue()) {
        cout << "a greater: " << a.getValue() << endl;
    }
    else {
        cout << "b greater: " << b.getValue() << endl;
    }
}



int main() {
    using Science::Math::pow;

    cout << "Custom call: " << pow(2, 3) << endl;

    cout << "Standart call: " << std::pow(2, 3) << endl;

    cout << endl;

    Science::Element<int> el1(10);
    Science::Element<int> el2(20);
    cout << "Comparing 10 and 20:" << endl;
    compareElements(el1, el2);

    Science::Element<string> el3("Banana");
    Science::Element<string> el4("Apple");

    cout << "Comparing Banana and Apple:" << endl;
    compareElements(el3, el4);

    return 0;
}