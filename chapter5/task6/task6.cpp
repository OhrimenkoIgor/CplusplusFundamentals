
#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int month_in_year = 12;
	const int years = 3;
	string months [month_in_year] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int sales [years][month_in_year] = {};

	for (int year = 1; year <= years; year++) {
		cout << "Enter sales per month for year " << year << ":" << endl;
		for (int i = 0; i < month_in_year; i++){
			cout << months[i] << ": ";
			(cin >> sales[year-1][i]).get();
		}
	}

	int sum[3] = {};
	for (int year = 0; year < years; year++){
		for (int i = 0; i < month_in_year; i++){
			sum[year] += sales[year][i];
		}
	}

	int total_sum = 0;
	for (int year = 1; year <= years; year++){
		total_sum += sum[year-1];
		cout << "Sales per year " << year << ": " << sum[year-1] << endl;
	}
	cout << "Total sales: " << total_sum << endl;

	cin.get();
	return 0;
}
