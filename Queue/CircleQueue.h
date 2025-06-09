#pragma once

#include<iostream>
using namespace std;

const int MAX_SIZE = 200;
const int DEFAULT_SIZE = 10;

template<typename T>
class CircleQueue {
    T* queue;
    int capacity;
    int size;
    int head;
    int end;
public:
    CircleQueue():capacity(DEFAULT_SIZE),size(0), head(0),end(0){
        cout << "The default queue capacity is " <<  DEFAULT_SIZE << endl;
        queue = new T[this->capacity];
    }
    CircleQueue(int capa) :size(0), head(0), end(0) {
        if (capa > MAX_SIZE || capa < 1) {
            cout<< "The maximum queue capacity is " << MAX_SIZE << ", the minimum capacity is 1. Out of range, set to " << DEFAULT_SIZE << " (default value)" << endl;
            this->capacity = DEFAULT_SIZE;
        }
        else {
            cout << "The  queue capacity is " << this->capacity << endl;
            this -> capacity = capa;
        }
        queue = new T[this->capacity];
    }
    ~CircleQueue() {
        delete[] queue;
    }

    int queue_length() {
        return size;
    }

    bool queue_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == capacity;
    }

    bool is_out(int index) {
        if (index == capacity - 1)
            return true;
        else if (index < 0)
            return true;
        return false;
    }
    //void clear_queue() {
    //    while (!queue_empty()) {
    //        out_queue();
    //    }
    //}

    void in_queue(T data) {
        if (is_full()) {
            cout << "Queue is full!" << endl;
            return;
        }
        queue[end] = data;
        end = (end + 1) % capacity;
        size++;
    }

    T out_queue() {
        if (queue_empty()) {
            cout << "This queue is empty!" << endl;
            return T();
        }
        T temp = queue[head];
        head = (head + 1) % capacity;
        size--;
        return temp;
    }

    T get_head() {
        if (size == 0) {
            cout << "This queue is empty." << endl;
            return T();
        }
        else {
            return queue[head];
        }
    }

    void print_queue() {
        if (size == 0) {
            cout << "This queue is empty." << endl;
        } else {
            int temp = head;
            for (int i = 0; i < size; i++) {
                cout << queue[temp] << " ";
                temp = (temp + 1) % capacity;
            }
            cout << endl;
        }
    }

    //T out_queue() {
    //    if (queue_empty()) {
    //        std::cerr << "Queue is empty, cannot dequeue." << std::endl;
    //        return T();
    //    }
    //    Node* temp = head;
    //    T data = head->data;
    //    head = head->next;
    //    delete temp; // �ͷ��ڴ�
    //    size--;
    //    if (size == 0) {
    //        end = nullptr; // �������Ϊ�գ����� end
    //    }
    //    return data;
    //}

    //T get_head() {
    //    if (queue_empty()) {
    //        std::cerr << "Queue is empty, cannot get head." << std::endl;
    //        return T();
    //    }
    //    return head->data;
    //}

    //void print_queue() {
    //    Node* temp = head;
    //    while (temp != nullptr) {
    //        cout << temp->data << " ";
    //        temp = temp->next;
    //    }
    //    cout << endl;
    //}
};