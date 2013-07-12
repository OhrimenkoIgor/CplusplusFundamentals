
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int month_in_year = 12;
	string months [month_in_year] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int sales [month_in_year] = {};

	cout << "Enter sales per month:" << endl;
	for (int i = 0; i < month_in_year; i++){
		cout << months[i] << ": ";
		(cin >> sales[i]).get();
	}

	int sum = 0;
	for (int i = 0; i < month_in_year; i++){
		sum += sales[i];
	}

	cout << "Sales per year: " << sum << endl;
	
	cin.get();
	return 0;
}
