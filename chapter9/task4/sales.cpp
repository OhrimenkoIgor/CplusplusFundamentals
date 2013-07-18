#include <iostream>

#include "sales.h"

namespace SALES
{

	using namespace std;

	void setSales(Sales & s, const double ar[], int n){
		if(n < 1){
			s.average = 0;
			s.max = 0;
			s.min = 0;
			for (int i = 0; i < QUARTERS; i++){
				s.sales[i] = 0;
			}
			return;
		}

		double sum = 0;
		s.sales[0] = s.max = s.min = sum = ar[0];
		int i;
		double val;
		for (i = 1; i < n && i < QUARTERS; i++){
			s.sales[i] = val = ar[i];
			if(val > s.max) s.max = val;
			if(val < s.min) s.min = val;
			sum += val;
		}
		s.average = sum / i;
		for (; i < QUARTERS; i++){
			s.sales[i] = 0;
		}
	}

	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	void setSales(Sales & s){
		cout << "Enter sales by quarters: " << endl;
		for (int i = 0; i < QUARTERS; i++){
			cout << i + 1 << ": ";
			while (!(cin >> s.sales[i])) {
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Please enter a number: ";
			}
			cin.get();
		}

		double sum = 0;
		s.max = s.min = sum = s.sales[0];
		int i;
		double val;
		for (i = 1; i < QUARTERS; i++){
			val = s.sales[i];
			if(val > s.max) s.max = val;
			if(val < s.min) s.min = val;
			sum += val;
		}
		s.average = sum / i;
	}

	void showSales(const Sales & s){
		cout << "Sales by quarters: " << endl;
		for (int i = 0; i < QUARTERS; i++){
			cout << i + 1 << ": " << s.sales[i] << endl;
		}
		cout << "Average: " << s.average << endl;
		cout << "Max: " << s.max << endl;
		cout << "Min: " << s.min << endl;
	}
}