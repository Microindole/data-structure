//
// Created by microindole on 25-3-25.
//

#ifndef SEQUENTIALLISTS_H
#define SEQUENTIALLISTS_H
#include <iostream>

#endif //SEQUENTIALLISTS_H
const int MaxNumber = 100;
template<class T>
class Elements {
private:
    T array[MaxNumber];
    int size;
public:
    Elements() {
        this->size = 0;
    };

    void SetArray(T array[],int n) {
        for (int i = 0;i<n;i++) {
            this->array[i] = array[i];
        }
        this->size = n;
    }

    void Init() {
        int i = 0;
        size = 0;
        for (i = 0;i<MaxNumber;i++) {
            array[i] = NULL;
        }
    }

    bool IsEmpty() {
        return size == 0;
    }

    T getValue(int index) {
        if (index >= size || index < 0) {
            std::cout << "the input error";
            return -1;
        }else {
            return array[index];
        }
    }

    int IndexOf(T theElement) {
        for ( int i = 0 ;i<= size;i++) {
            if (theElement == array[i]) {
                return i;
            }
        }
        return -1;
    }

    // 插入算法
    void add(T newElement,int index) {
        if (size == MaxNumber) {
            std::cout<< "cannot add" <<std::endl;
        }else {
            if (index >= size || index < 0) {
                std::cout << "the input error";
            }else {
                for (int i = size; i > index; i--) {
                    array[i] = array[i-1];
                }array[index] = newElement;
                size++;
            }
        }
    }

    // 删除操作
    T Del(int index) {
        if (index >= size || index < 0) {
            std::cout << "the input error";
            return NULL;
        }else {
            T temp = array[index];
            for (int i = index;i< size;i++) {
                array[i] = array[i+1];
            }
            array[size-1] = NULL;
            this->size = size - 1;
            return temp;
        }
    }

    // 获得整个数组
    int getSize() {
        return size;
    }

    T getArray() {
        std::cout<<"The array's size is "<<this->size<<std::endl;
        std::cout<<"The array is: ";
        for (int i = 0;i<size;i++) {
            std::cout<<array[i]<<" ";
        }
        return array[0];
    }
};