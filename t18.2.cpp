#include <iostream>
#include <stack>
#include <stdexcept>

namespace CustomSpace {

    template <typename T>
    class Stack {
    private:
        struct Node {
            T data;
            Node* next;
            Node(T val) : data(val), next(nullptr) {}
        };

        Node* topNode;
        int elementCount;

    public:
        Stack() : topNode(nullptr), elementCount(0) {}

        ~Stack() {
            while (!empty()) {
                pop();
            }
        }

        void push(T value) {
            Node* newNode = new Node(value);
            newNode->next = topNode;
            topNode = newNode;
            elementCount++;
        }

        void pop() {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            elementCount--;
        }

        T top() const {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            return topNode->data;
        }

        bool empty() const {
            return topNode == nullptr;
        }

        int size() const {
            return elementCount;
        }
    };
}

template <typename StackType>
int readIntegersUntilZero(StackType& stackContainer) {
    int value;
    std::cout << "Enter integers (0 to stop): ";
    while (std::cin >> value && value != 0) {
        stackContainer.push(value);
    }
    return stackContainer.size();
}

template <typename StackType>
void printAndEmptyStack(StackType& stackContainer) {
    std::cout << "Stack content (LIFO): ";
    while (!stackContainer.empty()) {
        std::cout << stackContainer.top() << " ";
        stackContainer.pop();
    }
    std::cout << std::endl;
}

int main() {

    std::cout << "--- Testing Custom Stack (int) ---" << std::endl;
    CustomSpace::Stack<int> myStack;
    int count1 = readIntegersUntilZero(myStack);
    std::cout << "Elements count: " << count1 << std::endl;
    printAndEmptyStack(myStack);

    std::cout << std::endl;


    std::cout << "--- Testing STL Stack (int) ---" << std::endl;
    std::stack<int> stlStack;
    int count2 = readIntegersUntilZero(stlStack);
    std::cout << "Elements count: " << count2 << std::endl;
    printAndEmptyStack(stlStack);

    std::cout << std::endl;


    std::cout << "--- Testing Custom Stack (double) ---" << std::endl;
    CustomSpace::Stack<double> doubleStack;
    std::cout << "Enter doubles (manually pushing 1.1, 2.2, 3.3)..." << std::endl;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    std::cout << "Size: " << doubleStack.size() << std::endl;
    printAndEmptyStack(doubleStack);

    return 0;
}