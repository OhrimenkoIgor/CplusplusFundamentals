#include <iostream>

#include "sales.h"

namespace SALES
{

	using namespace std;

	Sales::Sales(const double ar[], int n){
		if(n < 1){
			average = 0;
			max = 0;
			min = 0;
			for (int i = 0; i < QUARTERS; i++){
				sales[i] = 0;
			}
			return;
		}

		double sum = 0;
		sales[0] = max = min = sum = ar[0];
		int i;
		double val;
		for (i = 1; i < n && i < QUARTERS; i++){
			sales[i] = val = ar[i];
			if(val > max) max = val;
			if(val < min) min = val;
			sum += val;
		}
		average = sum / i;
		for (; i < QUARTERS; i++){
			sales[i] = 0;
		}
	}

	void Sales::setSales(){
		double sales_arr[QUARTERS];
		cout << "Enter sales by quarters: " << endl;
		for (int i = 0; i < QUARTERS; i++){
			cout << i + 1 << ": ";
			while (!(cin >> sales_arr[i])) {
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Please enter a number: ";
			}
			cin.get();
		}
		*this = Sales(sales_arr, 4);				
	}

	void Sales::showSales() const{
		cout << "Sales by quarters: " << endl;
		for (int i = 0; i < QUARTERS; i++){
			cout << i + 1 << ": " << sales[i] << endl;
		}
		cout << "Average: " << average << endl;
		cout << "Max: " << max << endl;
		cout << "Min: " << min << endl;
	}
}
