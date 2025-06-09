
#include <iostream>
#include "Stack.h"
//#include "ArrayStack.h"
using namespace std;

int main(){
	string input;
	getline(cin, input);
	//get_result(input);
	if (match_parentheses(input)) {
		get_result(input);
	}
	else {
		cout << "括号输入不正确" << endl;
	}

}