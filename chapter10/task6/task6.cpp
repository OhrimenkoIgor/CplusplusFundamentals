
#include <iostream>

#include "move.h"

int main(){

	using namespace std;

	Move m1;
	cout << "Initial object 1: " << endl;
	m1.showmove();
	cout << endl;

	m1.reset(1.5, 7.4);
	cout << "Reset object 1: " << endl;
	m1.showmove();
	cout << endl;

	Move m2(7.5, 4.6);
	cout << "Initial object 2: " << endl;
	m2.showmove();
	cout << endl;

	Move m3 = m1.add(m2);
	cout << "Object 3 = object 1 add object 2: " << endl;
	m3.showmove();
	cout << endl;

	cin.get();
	return 0;
}