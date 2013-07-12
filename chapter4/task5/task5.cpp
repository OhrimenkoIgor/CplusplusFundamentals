// task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

struct CandyBar {
	string brand_name;
	double weight;
	int calories;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CandyBar snack = {
		"Mocha Munch", 
		2.3,
		350
	};

	cout << snack.brand_name << endl << snack.weight << endl << snack.calories << endl;

	cin.get();
	return 0;
}

