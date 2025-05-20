// LinearList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iostream>

#include "LinkedChain.h"
// #include"SequentialLists.h"


using namespace std;

int main() {
    //顺序表实现多项式相加
    // int num1,num2;
    // cout<<"请输入第1个多项式项数：(大于0)"<<endl;
    // cin>>num1;
    // cout<<"请输入第2个多项式项数：(大于0)"<<endl;
    // cin>>num2;
    // Elements<double> el1 = create_element<double>(num1);
    // Elements<double> el2 = create_element<double>(num2);
    // print_elements(polynomial_merge<double>(el1,el2));
    // 链表实现多项式相加
    int num1, num2;
    cout << "请输入第1个多项式项数：(大于0)" << endl;
    cin >> num1;
    cout << "请输入第2个多项式项数：(大于0)" << endl;
    cin >> num2;
    Poly<double>* temp = nullptr;
    polynomial_add(temp, num1, num2);

    return 0;
}

