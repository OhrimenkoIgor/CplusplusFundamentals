// task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string first_name, last_name;
	cout << "Enter your first name: ";
	getline(cin, first_name);
	cout << "Enter your last name: ";
	getline(cin, last_name);

	string single_string;
	single_string = last_name + ", " + first_name;
	cout << "Here’s the information in a single string: " << single_string;

	cin.get();
	return 0;
}

