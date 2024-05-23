#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& value);
    void pop();
    T& top();
    bool isEmpty() const;
    int size() const;
    void clear();
    void print() const;
};

template<typename T>
void Stack<T>::push(const T& value) {
    elements.push_back(value);
}

template<typename T>
void Stack<T>::pop() {
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elements.pop_back();
}

template<typename T>
T& Stack<T>::top() {
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elements.back();
}


template<typename T>
bool Stack<T>::isEmpty() const {
    return elements.empty();
}

template<typename T>
int Stack<T>::size() const {
    return elements.size();
}

template<typename T>
void Stack<T>::clear() {
    elements.clear();
}

template<typename T>
void Stack<T>::print() const {
    for (const T& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    Stack<int> stack;

    stack.push(11);
    stack.push(222);
    stack.push(3333);

    std::cout << "Stack elements: ";
    stack.print();

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    stack.clear();
    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
