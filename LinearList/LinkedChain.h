#pragma once

#include <iostream>
const int MaxNumberForLink = 100;



template<typename T>
class Poly {
    int ex{};
    T co;
public:
    Poly* next;

    Poly() = default;

    Poly(int ex, T co, Poly* next) {
        this->ex = ex;
        this->co = co;
        this->next = next;
    }

    void SetPoly(int ex, T co, Poly* next) {
        this->ex = ex;
        this->co = co;
        this->next = next;
    }

    int getEx() {
        return this->ex;
    }

    T getCo() {
        return this->co;
    }

    int getLength(Poly* head) {
        if (head->next == nullptr) {
            return 1;
        }
        int i = 2;
        Poly* temp = head->next;
        while (temp->next != nullptr) {
            i++;
            temp = temp->next;
        }
        return i;
    }    //  ʱ�临�Ӷ� O(n)

    bool checkIndex(int index, Poly* head) {
        int size = getLength(head);
        if (size == 0) {
            std::cout << "This LinkChain is null" << std::endl;
            return false;
        }
        if (index < 0 || index >= size) {
            std::cout << "index out of range" << std::endl;
            return false;
        }
        else {
            return true;
        }
    }

    int getIndexEx(int index, Poly* head) {
        int thisIndex = 0;
        Poly* temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        return temp->getEx();
    }

    T getIndexCo(int index, Poly* head) {
        int thisIndex = 0;
        Poly* temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        return temp->getCo();
    }

    int indexOf(T element, Poly* head) {
        Poly* temp = this->next;
        int index = 1;
        if (element == this->co) {
            return 0;
        }
        else if (element == temp->co) {
            return 1;
        }
        else {
            while (element != temp->co) {
                temp = temp->next;
                index++;
                if (!checkIndex(index, head)) {
                    std::cout << "index out of range" << std::endl;
                    return -1;
                }
            }
            return index;
        }
    }

    Poly* getEndNode(Poly* head) {
        Poly* temp = this->next;
        while (temp != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    int AddNode(Poly* newNode, int index, Poly* head) {
        int thisIndex = 0;
        Poly* temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        if (index == 0) {
            newNode->next = head;
            return 0;
        }
        else if (index == getLength(head) - 1) {
            getEndNode(newNode)->next = newNode;
            return indexOf(newNode->co, head);
        }
        else {
            Poly* tempNext = temp->next;
            temp->next = newNode;
            newNode->next = tempNext;
            return indexOf(newNode->co, head);
        }
    }

    // ɾ��ĳ���ڵ㣬���Խ���һ���ڵ�����ݿ������������ýڵ�ָ�����¸��ڵ�
    Poly* Delete(int index, Poly* head) {
        int thisIndex = 0;
        if (index == 0) {
            return head->next;
        }
        else if (index == getLength(head) - 1) {
            Poly* temp = head;
            while ((temp->next)->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nullptr;
            return head;
        }
        else {
            Poly* temp = head;
            while (thisIndex + 1 < index) {
                temp = temp->next;
                thisIndex++;
            }
            Poly* tempNext = (temp->next)->next;
            temp->next = tempNext;
            return head;
        }
    }

};

// ���롢��������
template<typename T>
Poly<T>* create_poly_chain_poly(int i) {
    T co; int ex, index = 0;
    std::cout << "�밴�ս���˳�����������(ע��һ��ֻ��" << i << "��)" << std::endl;
    Poly<T>* head = nullptr, * temp = nullptr;
    // std::cout<<"������(ϵ�� ָ��) (ָ������0):"<<std::endl;
    // std::cin>>co>>ex;
    while (index < i) {
        std::cout << "��" << index + 1 << "�������(ϵ�� ָ��):" << std::endl;
        std::cin >> co >> ex;
        temp = new Poly<T>;
        temp->SetPoly(ex, co, head);
        head = temp;
        index++;
    }
    return head;
}

template<typename T>
Poly<T>* merge_two_poly(Poly<T>* head1, Poly<T>* head2) {
    Poly<T>* temp = nullptr, * merge_poly_head = nullptr, * process_poly = nullptr;
    int size1 = temp->getLength(head1), size2 = temp->getLength(head2);
    int index1 = 0, index2 = 0;

    while (index1 < size1 && index2 < size2) {
        int ex1 = temp->getIndexEx(index1, head1), ex2 = temp->getIndexEx(index2, head2);
        T co1 = temp->getIndexCo(index1, head1), co2 = temp->getIndexCo(index2, head2);
        if (ex1 < ex2) {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex1, co1, merge_poly_head);
            merge_poly_head = process_poly;
            index1++;
        }
        else if (ex2 < ex1) {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex2, co2, merge_poly_head);
            merge_poly_head = process_poly;
            index2++;
        }
        else {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex1, co1 + co2, merge_poly_head);
            merge_poly_head = process_poly;
            index1++;
            index2++;
        }
    }
    while (index1 < size1) {
        int ex1 = temp->getIndexEx(index1, head1);
        T co1 = temp->getIndexCo(index1, head1);
        process_poly = new Poly<T>;
        process_poly->SetPoly(ex1, co1, merge_poly_head);
        merge_poly_head = process_poly;
        index1++;
    }
    while (index2 < size2) {
        int ex2 = temp->getIndexEx(index2, head2);
        T co2 = temp->getIndexCo(index2, head2);
        process_poly = new Poly<T>;
        process_poly->SetPoly(ex2, co2, merge_poly_head);
        merge_poly_head = process_poly;
        index2++;
    }
    return merge_poly_head;
}

template<typename T>
void print_poly(Poly<T>* new_head) {
    for (int i = 0; i < new_head->getLength(new_head); i++) {
        if (i == new_head->getLength(new_head) - 1) {
            if (new_head->getIndexEx(i, new_head) == 0) std::cout << new_head->getIndexCo(i, new_head) << std::endl;
            else std::cout << new_head->getIndexCo(i, new_head) << "x**(" << new_head->getIndexEx(i, new_head) << ")" << std::endl;
        }
        else std::cout << new_head->getIndexCo(i, new_head) << "x**(" << new_head->getIndexEx(i, new_head) << ") + ";
    }
}

template<typename T>
void polynomial_add(Poly<T>* temp, int size1, int size2) {
    Poly<T>* head1 = create_poly_chain_poly<T>(size1);
    for (int i = 0; i < temp->getLength(head1); i++) {
        std::cout << "ָ��: " << temp->getIndexEx(i, head1) << "   ϵ��: " << temp->getIndexCo(i, head1) << std::endl;
    }
    std::cout << std::endl;
    Poly<T>* head2 = create_poly_chain_poly<T>(size2);
    for (int i = 0; i < temp->getLength(head2); i++) {
        std::cout << "ָ��: " << temp->getIndexEx(i, head2) << "   ϵ��: " << temp->getIndexCo(i, head2) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "��������ʽ��ӵĽ��Ϊ��" << std::endl;
    Poly<T>* new_head = merge_two_poly(head1, head2);
    print_poly(new_head);
    delete_poly(new_head);
    delete_poly(head1);
    delete_poly(head2);
}

template<typename T>
void delete_poly(Poly<T>* head) {
    Poly<T>* temp_this = head;
    Poly<T>* temp_next = head->next;
    while (temp_next != nullptr) {
        delete temp_this;
        temp_this = temp_next;
        temp_next = temp_next->next;
    }
}

// // ����ð������ʵ����������
// template<typename T>
// Poly<T> sort_by_buble(Poly<T> * head) {
//     Poly<T> * new_head = head, temp = nullptr;
//
// }



// struct node{
//
//     datatype element;
//
//     struct node *next;
// };
// typedef struct node Node;
// int size;



