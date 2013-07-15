
#include <iostream>

using namespace std;

double count_taxes (double incomes){
	if (incomes <= 5000) 
		return 0;
	else {
		double taxes = 0;
		incomes -= 5000;
		if(incomes <= 10000){
			taxes += incomes * 0.10;
			return taxes;
		} else {
			taxes += 10000 * 0.10;
			incomes -= 10000;
			if(incomes <= 20000){
				taxes += incomes * 0.15;
				return taxes;
			} else {
				taxes += 20000 * 0.15;
				incomes -= 20000;
				taxes += incomes * 0.20;
				return taxes;
			}
		}
	}
}

int main(){

	double incomes;
	while(cout << "Enter incomes: ", cin >> incomes && incomes >= 0){		
		cout << "Taxes owed: " << count_taxes(incomes) << endl;
	}
	cin.clear();

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}

