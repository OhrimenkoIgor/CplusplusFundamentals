// task7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define CNSIZE 20

using namespace std;

struct Pizza {
	char company [CNSIZE];
	double diameter;
	double weight;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Pizza pizza;

	cout << "Enter the name of the pizza company: ";
	cin.getline(pizza.company, CNSIZE);
	cout << "Enter the diameter of the pizza: ";
	(cin >> pizza.diameter).get();
	cout << "Enter the weight of the pizza: ";
	(cin >> pizza.weight).get();

	cout << endl << "Your pizza:" << endl;
	cout << pizza.company << endl
		<< pizza.diameter << endl
		<< pizza.weight << endl;

	cin.get();
	return 0;
}

