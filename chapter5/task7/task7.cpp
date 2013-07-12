
#include <iostream>
#include <string>

using namespace std;

struct Car {
	string make;
	int year;
};

int main()
{
	int num_cars = 0;
	cout << "How many cars do you wish to catalog? ";
	(cin >> num_cars).get();

	Car * cars = new Car [num_cars];

	for(int i = 0; i < num_cars; i++){
		cout << "Car # " << i+1 << ":" << endl;
		cout << "Please enter the make: ";
		getline (cin, cars[i].make);
		cout << "Please enter the year made: ";
		(cin >> cars[i].year).get();
	}

	cout << "Here is your collection:" << endl;
	for(int i = 0; i < num_cars; i++){
		cout << cars[i].year << " " << cars[i].make << endl;
	}

	cin.get();
	return 0;
}
