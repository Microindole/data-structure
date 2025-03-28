//
// Created by microindole on 25-3-25.
//


#include<iostream>
#include "SequentialLists.h"

using namespace std;

int main() {
    cout<<"Enter the elements of the array"<<endl;
    Elements<int> A;
    int array[10] ={0,1,2,3,4,5,6,7,8,9};
    A.SetArray(array,10);
    cout<<"Array after SetArray"<<endl;
    cout<<A.getValue(3)<<endl;
    A.getArray();
    cout<<A.Del(4)<<endl;
    A.getArray();

    return 0;
}
