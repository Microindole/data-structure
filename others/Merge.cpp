#include<iostream>

using namespace std;

int a[] = {1,3,5,7,9};
int b[] = {0,2,4,6,8};
void main() {
    int c[10];
    int index_a = 0, index_b = 0, index_c = 0;
    while (index_a < 5 && index_b < 5) {
    	int item_a = a[index_a], item_b = b[index_b];
    	if (item_a <= item_b) {
    		c[index_c] = item_a;index_a++;
    	}else {
    		c[index_c] = item_b;index_b++;
    	}
    	index_c++;
    }
    while (index_c < 10) {
    	if (index_a < index_b) {
    		c[index_c] = a[index_a];	index_a++;
    	}else {
    		c[index_c] = b[index_b];	index_b++;
    	}
    	index_c++;
    }for (int i = 0; i < index_c; i++)
    	cout << c[i] << "   ";
}

