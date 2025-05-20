#pragma once
#include <iostream>


const int MaxNumber = 100;
template<typename T>
class Elements {
private:
    int ex[MaxNumber];
    T co[MaxNumber];
    int size;
public:
    Elements() {}

    Elements(int ex[], T co[], int size) {
        this->size = size;
        for (int i = 0; i < size; i++) {
            this->ex[i] = ex[i];
            this->co[i] = co[i];
        }
    }

    void Init() {
        int i = 0;
        size = 0;
        for (i = 0; i < MaxNumber; i++) {
            ex[i] = 0;
            co[i] = NULL;
        }
    }

    bool IsEmpty() {
        return size == 0;
    }

    T get_index_co(int index) {
        if (index >= size || index < 0) {
            std::cout << "the input error";
            return co[0];
        }
        else {
            return co[index];
        }
    }

    int get_index_ex(int index) {
        if (index >= size || index < 0) {
            std::cout << "the input error";
            return -1;
        }
        else {
            return ex[index];
        }
    }

    int  get_size() {
        return size;
    }

    int index_of_ex(int num) {
        for (int i = 0; i <= size; i++) {
            if (num == ex[i]) {
                return i;
            }
        }
        return -1;
    }

    int index_of_co(T theElement) {
        for (int i = 0; i <= size; i++) {
            if (theElement == co[i]) {
                return i;
            }
        }
        return -1;
    }

    // 插入算法
    void add(T newElement, int index) {
        if (size == MaxNumber) {
            std::cout << "cannot add" << std::endl;
        }
        else {
            if (index >= size || index < 0) {
                std::cout << "the input error";
            }
            else {
                for (int i = size; i > index; i--) {
                    co[i] = co[i - 1];
                }co[index] = newElement;
                size++;
            }
        }
    }

    // 删除操作
    T Del(int index) {
        if (index >= size || index < 0) {
            std::cout << "the input error";
            return NULL;
        }
        else {
            T temp = co[index];
            for (int i = index; i < size; i++) {
                co[i] = co[i + 1];
            }
            co[size - 1] = NULL;
            this->size = size - 1;
            return temp;
        }
    }
};

template<typename T>
Elements<T> create_long_int(int size) {
    char* long_number = new char[size];
    std::cout << "请输入数字：(注意,数字为" << size << "位)" << std::endl;
    std::cin >> long_number;
    for (int i = size - 1; i >= (size + 1) / 2; i--) {
        if (i > i - size + 1) {
            char temp = long_number[i];
            long_number[i] = long_number[i - size + 1];
            long_number[i - size + 1] = temp;
        }
    }

}


template<typename T>
Elements<T> create_element(int size) {
    std::cout << "请按照降幂顺序输入具体的项：(注意一共只有" << size << "项)" << std::endl;
    T co[size];
    int ex[size];
    for (int i = 0; i < size; i++) {
        std::cout << "第" << i + 1 << "项，请输入(系数 指数):" << std::endl;
        std::cin >> co[i] >> ex[i];
    }
    return Elements(ex, co, size);
}

template<typename T>
Elements<T> polynomial_merge(Elements<T> poly1, Elements<T> poly2) {
    int size = 0;
    int new_ex[MaxNumber]; T new_co[MaxNumber];
    int index1 = 0, index2 = 0;
    int size1 = poly1.get_size(), size2 = poly2.get_size();
    while (index1 < size1 && index2 < size2) {
        int ex1 = poly1.get_index_ex(index1), ex2 = poly2.get_index_ex(index2);
        T co1 = poly1.get_index_co(index1), co2 = poly2.get_index_co(index2);
        if (ex1 < ex2) {
            new_co[size] = co2;
            new_ex[size] = ex2;
            index2++;
        }
        else if (ex2 < ex1) {
            new_co[size] = co1;
            new_ex[size] = ex1;
            index1++;
        }
        else {
            new_co[size] = co1 + co2;
            new_ex[size] = ex1;
            index2++;
            index1++;
        }
        size++;
    }
    while (index1 < size1) {
        new_co[size] = poly1.get_index_co(index1);
        new_ex[size] = poly1.get_index_ex(index1);
        size++;
        index1++;
    }
    while (index2 < size2) {
        new_co[size] = poly2.get_index_co(index2);
        new_ex[size] = poly2.get_index_ex(index2);
        size++;
        index2++;
    }
    Elements<T> new_poly(new_ex, new_co, size);
    return new_poly;
}

// 打印该类
template<typename T>
void print_elements(Elements<T> poly) {
    int size = poly.get_size();
    for (int i = 0; i < size; i++) {
        int ex = poly.get_index_ex(i);
        T co = poly.get_index_co(i);
        if (i == size - 1) {
            if (ex == 0) std::cout << co << std::endl;
            else std::cout << co << "x**(" << ex << ")" << std::endl;
        }
        else std::cout << co << "x**(" << ex << ") + ";
    }
}
