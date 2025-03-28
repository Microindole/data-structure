//
// Created by microindole on 25-3-28.
//

#ifndef LINKEDCHAIN_H
#define LINKEDCHAIN_H

#endif //LINKEDCHAIN_H
const int MaxNumber = 100;

bool inline check() {}


template<typename T>
class Node {
private:
    T theElement;
    Node * next;
public:
    Node(){}

    Node(T theElemrent, Node * next) {
        this->theElement = theElement;
        this->next = next;
    }

    int getLength(Node * head) {
        Node * temp;
        int i = 0;
        if (temp == nullptr)
            return i;
        while (temp != nullptr) {
            i++;
            temp = temp->next;
        }
        return i;
    }    //  时间复杂度 O(n)


};


// struct node{
//
//     datatype element;
//
//     struct node *next;
// };
// typedef struct node Node;
// int size;