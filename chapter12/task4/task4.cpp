
#include <iostream>
#include "stack.h"

using namespace std;

int main(){

	Stack stack1, stack3;

	for (int i = 0; !stack1.isfull(); i++){
		stack1.push(i);
	}

	Stack stack2 = stack1;
	stack3 = stack2;

	Item item = 0;
	cout << "Stack1:" << endl;
	while(!stack1.isempty()){
		stack1.pop(item);
		cout << item << endl;
	}

	cout << "Stack2:" << endl;
	while(!stack2.isempty()){
		stack2.pop(item);
		cout << item << endl;
	}

	cout << "Stack3:" << endl;
	while(!stack3.isempty()){
		stack3.pop(item);
		cout << item << endl;
	}


	cin.get();
	return 0;
}

