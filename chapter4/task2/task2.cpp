// task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	string name;
	string dessert;
	cout << "Enter your name:\n";
	getline(cin, name); // reads through newline
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	cin.get();
	return 0;

}

