#pragma once

#include<iostream>
#include<string>

const int Max_Size = 10000;
const int Default_Size = 10;

template <typename T>
class ArrayStack {
	T * array_stack;
	int size;
	int index;
public:
	ArrayStack() :size(Default_Size), index(-1) {
		array_stack = new T[size];
	}

	ArrayStack(int size) :index(-1) {
		if (size > Max_Size || size <= 0) {
			this->size = Default_Size;
			std::cout << "The maximum stack capacity is " << Max_Size << ", the minimum capacity is 1. Out of range, set to " << Default_Size << " (default value)" << std::endl;
			array_stack = new T[Default_Size];
		}
		else {
			this->size = size;
			array_stack = new T[size];
		}
	}
	 
	~ArrayStack() {
		delete[] array_stack;
	}

	bool empty() const{
		return index == -1;
	}

	int get_size() const {
		return this->size;
	}

	void push(T data) {
		if (index == size - 1) {
			std::cout << "Stack is full, cannot push." << std::endl;
			std::cout << "The top of the stack is " << array_stack[index] << std::endl;
		}
		index++;
		array_stack[index] = data;
		
	}

	T pop() {
		if (empty()) {
			std::cerr << "Stack is empty, cannot pop." << std::endl;
            return T();
		}
		T data = array_stack[index];
		index--;
		return data;
	}

	T peek() const {
		if (empty()) {
			std::cerr << "Stack is empty, cannot peek." << std::endl;
			return T();
		}
		return array_stack[index];
	}

	void pring_stack() const {
		if (empty()) {
			std::cout << "Stack is empty." << std::endl;
			return;
		}
		for (int i = 0; i <= index; i++) {
			std::cout << array_stack[i] << " ";
		}
	}
};