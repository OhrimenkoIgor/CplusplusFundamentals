#include <iostream>

double harmonic (double x, double y){
	return 2.0 * x * y / (x + y);
}

int main (){

	using namespace std;

	double x, y;
	x = y = 0;
	while (cout << "Enter pair: ", cin >> x >> y && x != 0 && y != 0){
		cout << "Harmonic is: " << harmonic (x ,y) << endl;
	}

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}
