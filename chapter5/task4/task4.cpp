
#include <iostream>
#include <array>

using namespace std;

int main()
{
	double daphne_balance = 100, cleo_balance = 100;
	double daphne_original_balance = daphne_balance;

	int i = 0;
	for ( i = 0; daphne_balance >= cleo_balance; i++){
		daphne_balance += 0.10 * daphne_original_balance;
		cleo_balance += 0.05 * cleo_balance;
	}

	cout << i << " years it takes for the value of Cleo’s investment to exceed the value of Daphne’s investment" << endl;
	cout << "Cleo’s investment:   " << cleo_balance << endl;
	cout << "Daphne’s investment: " << daphne_balance << endl;
	
	cin.get();
	return 0;
}
