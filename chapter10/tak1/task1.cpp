
#include <iostream>
#include <string>

#include "account.h"

int main(){

	using std::cout;
	using std::endl;

	account acc("John", "TE9734");

	cout << "Accaunt: " << endl;
	acc.display();

	double add = 42897;
	cout << "Deposit: " << add << endl;
	acc.deposit(add);

	cout << "Accaunt: " << endl;
	acc.display();

	double spend = 12346.5;
	cout << "Windtrow: " << spend << endl;
	acc.withdraw(spend);

	cout << "Accaunt: " << endl;
	acc.display();

	std::cin.get();

	return 0;
}