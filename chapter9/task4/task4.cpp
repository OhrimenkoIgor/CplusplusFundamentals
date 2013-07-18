
#include <iostream>

#include "sales.h"

int main(){

	using namespace SALES;
	using std::cin;
	using std::cout;
	using std::endl;

	Sales s1, s2;

	const int sales1_size = 3;
	double sales1 [sales1_size] = {4.6, 2.4, 3};

	setSales(s1, sales1, sales1_size);

	setSales(s2);

	cout << "Sales 1: " << endl;
	showSales(s1);

	cout << "Sales 2: " << endl;
	showSales(s2);

	cin.get();

	return 0;
}