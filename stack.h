#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack(); 
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
Stack<T>::Stack() {
}

template <typename T>
Stack<T>::~Stack() {
}

// size check
template <typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size(); 
}

// empty check
template <typename T>
bool Stack<T>::empty() const{
    return std::vector<T>::empty(); 
}

// push function 
template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item); 
}

// checking if vector is empty and throwing error, if not then removing element at top
template <typename T>
void Stack<T>::pop() {
    if (std::vector<T>::empty()) {
        throw std::underflow_error("The Stack is Empty"); 
    } else {
        std::vector<T>::pop_back(); 
    }
}

// checking if vector is empty and throwing error, if not then returning front reference
template <typename T>
const T& Stack<T>::top() const {
    if (std::vector<T>::empty()) {
        throw std::underflow_error("The Stack is Empty"); 
    } else {
        return std::vector<T>::back(); 
    }
    
}

#endif