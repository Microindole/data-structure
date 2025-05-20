#include<iostream>
using namespace std;
long getNum(long num) {
	if (num == 1 || num == 2) {
		return 1;
	}else {
		return getNum(num - 1) + getNum(num - 2);
	}
}

int main() {
	long num;
	cin >> num;
	long result = getNum(num);
	cout << result << endl;
	return 0;
}