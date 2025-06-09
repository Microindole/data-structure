#pragma once

template<typename T>
struct StackNode{
    T data;
    StackNode* next;
    StackNode(T value) : data(value), next(nullptr) {}
};

template<typename T>
class stack {
private:
    StackNode<T>* topNode;
public:
    stack() : topNode(nullptr) {}

    ~stack() {
        clear();
    }

    void push(T value) {
        StackNode<T>* newNode = new StackNode<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) return;
        StackNode<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};