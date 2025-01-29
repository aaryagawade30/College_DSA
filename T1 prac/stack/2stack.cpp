#include <iostream>
#include <stdexcept>

class TwoStacks {
private:
    int* arr;      // Array to hold the two stacks
    int size;      // Total size of the array
    int top1;      // Top index for Stack 1
    int top2;      // Top index for Stack 2

public:
    // Constructor to initialize the array and stack pointers
    TwoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push an element into Stack 1
    void push1(int value) {
        if (top1 + 1 == top2) {
            throw std::overflow_error("Stack Overflow: No space to push in Stack 1");
        }
        arr[++top1] = value;
    }

    // Push an element into Stack 2
    void push2(int value) {
        if (top1 + 1 == top2) {
            throw std::overflow_error("Stack Overflow: No space to push in Stack 2");
        }
        arr[--top2] = value;
    }

    // Pop an element from Stack 1
    int pop1() {
        if (top1 == -1) {
            throw std::underflow_error("Stack Underflow: Stack 1 is empty");
        }
        return arr[top1--];
    }

    // Pop an element from Stack 2
    int pop2() {
        if (top2 == size) {
            throw std::underflow_error("Stack Underflow: Stack 2 is empty");
        }
        return arr[top2++];
    }

    // Display Stack 1 elements
    void displayStack1() {
        std::cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Display Stack 2 elements
    void displayStack2() {
        std::cout << "Stack 2: ";
        for (int i = size - 1; i >= top2; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Destructor to free the allocated memory
    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(5);
    ts.push1(10);
    ts.push1(15);
    ts.displayStack1();

    ts.push2(11);
    ts.push2(9);
    ts.push2(7);
    ts.displayStack2();

    std::cout << "Popped from Stack 1: " << ts.pop1() << std::endl;
    ts.displayStack1();

    std::cout << "Popped from Stack 2: " << ts.pop2() << std::endl;
    ts.displayStack2();

    return 0;
}
