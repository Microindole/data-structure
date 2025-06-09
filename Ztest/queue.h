#pragma once

template <typename T>
struct QueueNode{
    T data;
    QueueNode* next;

    QueueNode(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
    private:
        QueueNode<T>* front;
        QueueNode<T>* rear;
        int size;
    public:
        Queue() : front(nullptr), rear(nullptr), size(0) {}

        ~Queue() {
            clear();
        }

        void enqueue(T value) {
            QueueNode<T>* newNode = new QueueNode<T>(value);
            if (rear) {
                rear->next = newNode;
            } else {
                front = newNode;
            }
            rear = newNode;
            size++;
        }

        void dequeue() {
            if (isEmpty()) return;
            QueueNode<T>* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (isEmpty()) {
                rear = nullptr;
            }
        }

        T peek() const {
            if (isEmpty()) throw std::runtime_error("Queue is empty");
            return front->data;
        }

        bool isEmpty() const {
            return size == 0;
        }

        int getSize() const {
            return size;
        }
    
        void clear() {
            while (!isEmpty()) {
                dequeue();
            }
        }
    };