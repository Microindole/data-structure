#pragma once

#include <iostream>
#include <string>
#include <cmath>

const int MAX_SIZE = 10000;
const int DEFAULT_SIZE = 10;
const char letter[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                          'o', 'p', 'q', 'r', 's', 't', 
                          'u', 'v', 'w', 'x', 'y', 'z'};

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

    void set_capacity(int capac) const {
        if (capac > MAX_SIZE || capac <= 0) {
            this->capacity = DEFAULT_SIZE;
            std::cout << "The maximum stack capacity is " << MAX_SIZE << ", the minimum capacity is 1. Out of range, set to " << DEFAULT_SIZE << " (default value)" << std::endl;
            ;
        }
        else {
			this->capacity = capac;
        }
    }

    // 判断栈是否为空
    bool empty(){
        return top == nullptr;
    }

    // 获取栈的大小
    int get_size() {
        return size;
    }

    // 入栈操作
    void push(T data){
        if (size == capacity) {
            std::cerr << "Stack is full, cannot push." << std::endl;
            std::cout << "The top of the stack is " << top->data << std::endl;
       
        }
        Node* new_node = new Node(data, top);
        top = new_node;
        size++;
    }

    // 出栈操作
    T pop(){
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

    // 获取栈顶元素
    T peek() {
        if (empty()) {
            std::cerr << "Stack is empty, cannot peek." << std::endl;
            return T();
        }
        return top->data;
    }

	void clear(){
		while (!empty()) {
			pop();
		}
	}

    // 打印栈中的所有元素
    void print_stack(){
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

bool current_op(int left, int right) {
    return (left != -1 && right != -1);
}


bool match_parentheses(std::string str){
	int len = str.length();
	Stack<char> stack(len);
	for (char ch : str) {
		if (ch == '(' || ch == '[' || ch == '{') {
			stack.push(ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (stack.empty()) {
				return false;
			}
			char top = stack.pop();
			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{')) {
				return false;
			}
		}
	}
	return stack.empty();
}

int left_op(char ch) {
    switch (ch) {
    case '#': 	return 0;
    case '(': 	return 1;
    case '+': 	return 3;
    case '-': 	return 3;
    case '*': 	return 5;
    case '/': 	return 5;
    case '%': 	return 5;
    case '^': 	return 7;
    case ')': 	return 8;
    }
}

int right_op(char ch) {
    switch (ch) {
    case '#': 	return 0;
    case '(': 	return 8;
    case '+': 	return 2;
    case '-': 	return 2;
    case '*': 	return 4;
    case '/': 	return 4;
    case '%': 	return 4;
    case '^': 	return 6;
    case ')': 	return 1;
    }
}

char calculate_char(char op1, char op2, char ch, double value[]) {
    char new_op1 = op1;
    double d_op1 = value[op1 - 'a'];
    double d_op2 = value[op2 - 'a'];
    double d_op3 = 0;
    switch (ch){
    case '+':
        d_op3 = d_op1 + d_op2;
        break;
    case '-':
        d_op3 = d_op1 - d_op2;
        break;
    case '*':
        d_op3 = d_op1 * d_op2;
        break;
    case '/':
        d_op3 = d_op1 / d_op2;
        break;
    case '%':
        d_op3 = static_cast<double>(static_cast<int>(d_op1) % static_cast<int>(d_op2));
        break;
    case '^':
        d_op3 = pow(d_op1, d_op2);
        break;

    default:
        break;
    }
    value[op1 - 'a'] = d_op3;

    return new_op1;
}

// 词法分析：解析输入字符串并将操作数和操作符存入 old_tokens
void tokenize_input(const std::string& input, Stack<std::string>& old_tokens, double value[], int& letter_index) {
    std::string current_number = "";
    bool has_dot = false;

    for (char current : input) {
        if (current == ' ') {
            // 跳过空格
            continue;
        } else if (isdigit(current)) {
            // 处理数字
            current_number += current;
        } else if (current == '.') {
            // 处理小数点
            if (has_dot) {
                std::cout << "Error: Invalid number format (multiple dots in number)" << std::endl;
                return;
            }
            has_dot = true;
            current_number += current;
        } else {
            // 如果当前字符不是数字或小数点，先将之前的数字作为一个标记存储
            if (!current_number.empty()) {
                if (letter_index >= 26) {
                    std::cout << "Error: Too many numbers, exceeded 26 variables." << std::endl;
                    return;
                }
                value[letter_index] = std::stod(current_number);
                old_tokens.push(std::string(1, letter[letter_index]));
                letter_index++;
                current_number = "";
                has_dot = false;
            }

            // 处理符号
            old_tokens.push(std::string(1, current));
        }
    }
    if (!current_number.empty()) {
        if (letter_index >= 26) {
            std::cout << "Error: Too many numbers, exceeded 26 variables." << std::endl;
            return;
        }
        value[letter_index] = std::stod(current_number);
        old_tokens.push(std::string(1, letter[letter_index]));
        letter_index++;
    }
}

// 转置栈
template <typename T>
void reverse_stack(Stack<T>& source, Stack<T>& destination) {
    while (!source.empty()) {
        destination.push(source.pop());
    }
}

void get_result(std::string input) {
    int len = input.length();
    Stack<std::string> old_tokens(len); 
    double value[26] = { 0 }; 
    int letter_index = 0; 

    // 调用词法分析函数
    tokenize_input(input, old_tokens, value, letter_index);

    // 将 old_tokens 转换为 new_tokens
    Stack<char> new_tokens(len);
    while (!old_tokens.empty()) {
        new_tokens.push(old_tokens.pop()[0]);
    }
    std::cout << std::endl;
    std::cout << "Lexical analysis results, extraction of operands:" << std::endl;

    // 打印标记
    new_tokens.print_stack();

    // 打印提取的数字及其对应的字母
    for (int i = 0; i < letter_index; i++) {
        std::cout << letter[i] << " = " << value[i] << std::endl;
    }

    // 转换 new_tokens 为后缀表达式
    Stack<char> op_stack(len);
    Stack<char> postfix_tokens(len);

    while (!new_tokens.empty()) {
        char ch = new_tokens.pop();

        // 如果是操作数，直接加入后缀表达式
        if (isalnum(ch)) {
            postfix_tokens.push(ch);
        }
        // 如果是左括号，直接入操作符栈
        else if (ch == '(') {
            op_stack.push(ch);
        }
        // 如果是右括号，弹出操作符栈直到遇到左括号
        else if (ch == ')') {
            while (!op_stack.empty() && op_stack.peek() != '(') {
                postfix_tokens.push(op_stack.pop());
            }
            if (!op_stack.empty() && op_stack.peek() == '(') {
                op_stack.pop();
            }
        }
        // 如果是操作符
        else {
            while (!op_stack.empty() && left_op(op_stack.peek()) >= right_op(ch)) {
                postfix_tokens.push(op_stack.pop());
            }
            op_stack.push(ch);
        }
    }

    // 将剩余的操作符全部弹出
    while (!op_stack.empty()) {
        postfix_tokens.push(op_stack.pop());
    }

    // 转置 postfix_tokens
    Stack<char> reversed_postfix(len);
    reverse_stack(postfix_tokens, reversed_postfix);

    // 打印转置后的后缀表达式
    std::cout << "Reversed Postfix Expression: ";
    reversed_postfix.print_stack();

    Stack<char> calculate_stack(reversed_postfix.get_size());
    calculate_stack.push(reversed_postfix.pop());
    calculate_stack.push(reversed_postfix.pop());
    while (calculate_stack.get_size() != 1 || !reversed_postfix.empty()) {
        char ch = reversed_postfix.pop();
        if (isalnum(ch)) {
            calculate_stack.push(ch);
        }
        else {
            char op2 = calculate_stack.pop();
            char op1 = calculate_stack.pop();
            char new_op = calculate_char(op1, op2, ch, value);
            calculate_stack.push(new_op);
        }
    }
    std::cout << std::endl;
    std::cout << "Calculation result: " << std::endl;
    std::cout << value[calculate_stack.pop() - 'a'] << std::endl;
}