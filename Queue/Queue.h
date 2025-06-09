#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };
    Node* head;
    Node* end;
    int size;

public:
    Queue() : head(nullptr), end(nullptr), size(0) {}
    ~Queue() {
        clear_queue();
    }

    int queue_length() {
        return size;
    }

    bool queue_empty() {
        return size == 0;
    }

    void clear_queue() {
        while (!queue_empty()) {
            out_queue();
        }
    }

    void in_queue(T data) {
        Node* new_node = new Node(data, nullptr);
        if (size == 0) {
            head = new_node;
        }
        else {
            end->next = new_node;
        }
        end = new_node;
        size++;
    }

    T out_queue() {
        if (queue_empty()) {
            std::cerr << "Queue is empty, cannot dequeue." << std::endl;
            return T();
        }
        Node* temp = head;
        T data = head->data;
        head = head->next;
        delete temp; // 释放内存
        size--;
        if (size == 0) {
            end = nullptr; // 如果队列为空，重置 end
        }
        return data;
    }

    T get_head() {
        if (queue_empty()) {
            std::cerr << "Queue is empty, cannot get head." << std::endl;
            return T();
        }
        return head->data;
    }

    void print_queue() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
