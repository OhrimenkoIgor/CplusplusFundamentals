
#include <iostream>

#include "sales.h"

int main(){

	using namespace SALES;
	using std::cin;
	using std::cout;
	using std::endl;

	const int sales1_size = 3;
	double sales1 [sales1_size] = {4.6, 2.4, 3};

	Sales s1(sales1, sales1_size);
	Sales s2;

	s2.setSales();

	cout << "Sales 1: " << endl;
	s1.showSales();

	cout << "Sales 2: " << endl;
	s2.showSales();

	cin.get();

	return 0;
}
