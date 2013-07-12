// task6.cpp : Defines the entry point for the console application.
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
	CandyBar three_bars [3] = { {"Mocha Munch", 2.3, 350}, {"Sunday", 0.5, 37}, {"Good Morning", 0.3, 54} };

	for (CandyBar * p = three_bars; p < three_bars + 3; p++){
		cout << p->brand_name << endl << p->weight << endl << p->calories << endl << endl;
	}

	cin.get();
	return 0;
}
