
#include <iostream>

#include "plorg.h"

int main(){

	using namespace std;

	Plorg plorg("Tram");
	cout << "Plorg: " << plorg.get_name() << ", CI = " << plorg.get_ci() << endl;

	plorg.set_ci(40);
	cout << "Now: " << plorg.get_name() << ", CI = " << plorg.get_ci() << endl;

	Plorg plorg2;
	cout << "Default plorg: " << plorg2.get_name() << ", CI = " << plorg2.get_ci() << endl;

	cin.get();
}
