// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int size = 20;
	char first_name [size], last_name [size];
	cout << "Enter your first name: ";
	cin.getline(first_name, size);
	cout << "Enter your last name: ";
	cin.getline(last_name, size);

	char single_string [2*size+2];
	strcpy(single_string, last_name);
	strcat(single_string, ", ");
	strcat(single_string, first_name);
	cout << "Here’s the information in a single string: " << single_string;

	cin.get();
	return 0;
}

