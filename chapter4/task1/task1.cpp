// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string first_name, last_name;
	char grade;
	int age;
	cout << "What is your first name? ";
	getline(cin, first_name);
	cout << "What is your last name? ";
	getline(cin, last_name);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age? ";
	(cin >> age).get();

	cout << "Name: " << last_name << ", " << first_name << endl;
	cout << "Grade: " << char(grade+1) << endl;
	cout << "Age: " << age << endl;

	cin.get();

	return 0;
}

