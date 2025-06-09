#include<iostream>


#include"merge.h"
#include"stack.h"
#include"queue.h"

using namespace std;

void merge11() {
	double arr1[7] = { 1,4,7,8,19,234,888 };
	double arr2[5] = { 0,2,3,6,456 };
	print_arr(arr1, 7);
	print_arr(arr2, 5);
	double* arr3 = new double[get_merge_size(7, 5)];
	merge(arr1, arr2, arr3, 7, 5);
	print_arr(arr3, get_merge_size(7, 5));
	delete[] arr3;
}

void teststack() {
	//merge11();
	stack<int> sk1;
	sk1.push(123);
	cout << sk1.top() << endl;
	sk1.push(456);
	cout << sk1.top() << endl;
	sk1.pop();
	cout << sk1.top() << endl;
}

void print_underline() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

int main() {
	
	merge11();
	print_underline();
	teststack();




	return 0;
}