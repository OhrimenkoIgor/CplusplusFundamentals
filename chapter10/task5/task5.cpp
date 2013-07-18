
#include <iostream>

#include "stack.h"

using namespace std;

void show_menu(){
	cout << "Enter customer payments:" << endl
		<< "a) add	r) remove	q) quit" << endl;
}

void enterstruct(customer & item){
	cout << "Enter name: ";
	cin.get(item.fullname, 35);
	while(cin.get() != '\n');
	cout << "Enter payment: ";
	while (!(cin >> item.payment)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a number: ";
	}
}

int main(){

	Stack stack;
	char ch;
	double total = 0;

	customer item;

	show_menu();
	while (cin >> ch && ch != 'q'){
		while (cin.get() != '\n');
		switch(ch){
		case 'a':
			enterstruct(item);
			stack.push(item);
			break;
		case 'r':
			if(stack.pop(item)){
				total += item.payment;
				cout << "Total: " << total << endl;
			} else {
				cout << "Stack is emty" << endl;
			}
			break;
		}
		show_menu();
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	return 0;
}