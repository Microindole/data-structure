//
// Created by microindole on 25-3-28.
//

#ifndef LINKEDCHAIN_H
#define LINKEDCHAIN_H
#include <iostream>
#include <ostream>

#endif //LINKEDCHAIN_H
const int MaxNumber = 100;



template<typename T>
class Poly {
private:
    int ex;
    T co;
    Poly * next;
public:

    Poly()= default;

    Poly(int ex,T co, Poly * next) {
        this->ex = ex;
        this->co = co;
        this->next = next;
    }

    void SetPoly(int ex,T co, Poly * next) {
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

    int getLength(Poly * head) {
        if (head->next == nullptr) {
            return 1;
        }
        int i = 2;
        Poly * temp = head->next;
        while (temp->next != nullptr) {
            i++;
            temp = temp->next;
        }
        return i;
    }    //  时间复杂度 O(n)

    bool checkIndex(int index,Poly * head) {
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

    int getIndexEx(int index,Poly * head) {
        int thisIndex = 0;
        Poly * temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        return temp->getEx();
    }

    T getIndexCo(int index,Poly * head) {
        int thisIndex = 0;
        Poly * temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        return temp->getCo();
    }

    int indexOf(T element,Poly * head) {
        Poly * temp = this->next;
        int index = 1;
        if (element == this->co) {
            return 0;
        }else if (element == temp->co) {
            return 1;
        }else {
            while (element != temp->co) {
                temp = temp->next;
                index++;
                if (!checkIndex(index,head)) {
                    std::cout << "index out of range" << std::endl;
                    return -1;
                }
            }
            return index;
        }
    }

    Poly * getEndNode(Poly * head) {
        Poly * temp = this->next;
        while (temp != nullptr) {
            temp = temp->next;
        }
        return temp;
    }

    int AddNode(Poly * newNode,int index,Poly * head) {
        int thisIndex = 0;
        Poly * temp = head;
        while (thisIndex < index) {
            temp = temp->next;
            thisIndex++;
        }
        if (index == 0) {
            newNode->next = head;
            return 0;
        }
        else if (index == getLength(head)-1) {
            getEndNode(newNode)->next = newNode;
            return indexOf(newNode->co,head);
        }
        else {
            Poly * tempNext = temp->next;
            temp->next = newNode;
            newNode->next = tempNext;
            return indexOf(newNode->co,head);
        }
    }


    // 删除莫个节点，可以将下一个节点的数据拷贝过来，将该节点指向下下个节点
    Poly* Delete(int index,Poly * head) {
        int thisIndex = 0;
        if (index == 0) {
            return head->next;
        }else if (index == getLength(head) - 1) {
            Poly * temp = head;
            while ((temp->next)->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nullptr;
            return head;
        }else {
            Poly * temp = head;
            while (thisIndex+1 < index) {
                temp = temp->next;
                thisIndex++;
            }
            Poly * tempNext = (temp->next)->next;
            temp->next = tempNext;
            return head;
        }
    }

};

// 输入、创建链表
template<typename T>
Poly<T> * create_poly_chain_poly() {
    T co;int ex;
    std::cout<<"请按照降幂顺序输入具体的项：(否则后果自负)"<<std::endl;
    Poly<T> * head = nullptr, * temp =nullptr;
    std::cout<<"请输入(系数 指数) (指数大于0):"<<std::endl;
    std::cin>>co>>ex;
    while (ex > -1) {
        temp = new Poly<T>;
        temp->SetPoly(ex,co,head);
        head = temp;
        std::cout<<"请输入(系数 指数) (指数大于0):"<<std::endl;
        std::cin>>co>>ex;
    }
    return head;
}

template<typename T>
Poly<T> * merge_two_poly(Poly<T> * head1,Poly<T> * head2) {
    Poly<T> * temp = nullptr, * merge_poly_head = nullptr, * process_poly = nullptr;
    int size1 = temp->getLength(head1),size2 = temp->getLength(head2);
    int index1 = 0, index2 = 0;

    while (index1 < size1 && index2 < size2) {
        int ex1 = temp->getIndexEx(index1,head1),ex2 = temp->getIndexEx(index2,head2);
        T co1 = temp->getIndexCo(index1,head1),co2 = temp->getIndexCo(index2,head2);
        if (ex1 < ex2) {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex1,co1,merge_poly_head);
            merge_poly_head = process_poly;
            index1++;
        }
        else if (ex2 < ex1) {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex2,co2,merge_poly_head);
            merge_poly_head = process_poly;
            index2++;
        }else {
            process_poly = new Poly<T>;
            process_poly->SetPoly(ex1,co1+co2,merge_poly_head);
            merge_poly_head = process_poly;
            index1++;
            index2++;
        }
    }
    while (index1 < size1) {
        int ex1 = temp->getIndexEx(index1,head1);
        T co1 = temp->getIndexCo(index1,head1);
        process_poly = new Poly<T>;
        process_poly->SetPoly(ex1,co1,merge_poly_head);
        merge_poly_head = process_poly;
        index1++;
    }
    while (index2 < size2) {
        int ex2 = temp->getIndexEx(index2,head2);
        T co2 = temp->getIndexCo(index2,head2);
        process_poly = new Poly<T>;
        process_poly->SetPoly(ex2,co2,merge_poly_head);
        merge_poly_head = process_poly;
        index2++;
    }
    return merge_poly_head;
}

template<typename T>
void polynomial_add(Poly<T> * temp) {
    Poly<T> * head1 = create_poly_chain_poly<T>();
    for (int i = 0;i < temp->getLength(head1);i++) {
        std::cout<<"指数: "<<temp->getIndexEx(i,head1)<<"   系数: "<<temp->getIndexCo(i,head1)<<std::endl;
    }
    std::cout<<std::endl;
    Poly<T> * head2 = create_poly_chain_poly<T>();
    for (int i = 0;i < temp->getLength(head2);i++) {
        std::cout<<"指数: "<<temp->getIndexEx(i,head2)<<"   系数: "<<temp->getIndexCo(i,head2)<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"两个多项式相加的结果为："<<std::endl;
    Poly<T> * new_head = merge_two_poly(head1,head2);
    for (int i = 0;i < temp->getLength(new_head);i++) {
        if (i == temp->getLength(new_head) - 1) {
            if (temp->getIndexEx(i,new_head) == 0 ) std::cout<<temp->getIndexCo(i,new_head)<<std::endl;
            else std::cout<<temp->getIndexCo(i,new_head)<<"x**("<<temp->getIndexEx(i,new_head)<<")"<<std::endl;
        }else std::cout<<temp->getIndexCo(i,new_head)<<"x**("<<temp->getIndexEx(i,new_head)<<") + ";
    }
}

// struct node{
//
//     datatype element;
//
//     struct node *next;
// };
// typedef struct node Node;
// int size;