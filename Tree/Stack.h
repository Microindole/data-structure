#pragma once


#include <iostream>
#include <string>
#include <cmath>

const int MAX_SIZE = 10000;
const int DEFAULT_SIZE = 100;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* top;
    int size;
    int capacity;

public:
    Stack() : top(nullptr), size(0) {
        capacity = DEFAULT_SIZE;
    }
    Stack(int capac) : top(nullptr), size(0) {
        if (capac > MAX_SIZE || capac <= 0) {
            this->capacity = DEFAULT_SIZE;
            std::cout << "The maximum stack capacity is " << MAX_SIZE << ", the minimum capacity is 1. Out of range, set to " << DEFAULT_SIZE << " (default value)" << std::endl;
            ;
        }
        else {
            this->capacity = capac;
        }
    }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    void set_capacity(int capac) {
        if (capac > MAX_SIZE || capac <= 0) {
            this->capacity = DEFAULT_SIZE;
            std::cout << "The maximum stack capacity is " << MAX_SIZE << ", the minimum capacity is 1. Out of range, set to " << DEFAULT_SIZE << " (default value)" << std::endl;
            ;
        }
        else {
            this->capacity = capac;
        }
    }

    // �ж�ջ�Ƿ�Ϊ��
    bool empty() {
        return top == nullptr;
    }

    // ��ȡջ�Ĵ�С
    int get_size() {
        return size;
    }

    // ��ջ����
    void push(T data) {
        if (size == capacity) {
            std::cerr << "Stack is full, cannot push." << std::endl;
            std::cout << "The top of the stack is " << top->data << std::endl;

        }
        Node* new_node = new Node(data, top);
        top = new_node;
        size++;
    }

    // ��ջ����
    T pop() {
        if (empty()) {
            std::cerr << "Stack is empty, cannot pop." << std::endl;
            return T();
        }

        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    // ��ȡջ��Ԫ��
    T peek() {
        if (empty()) {
            std::cerr << "Stack is empty, cannot peek." << std::endl;
            return T();
        }
        return top->data;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }

    // ��ӡջ�е�����Ԫ��
    void print_stack() {
        if (empty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

