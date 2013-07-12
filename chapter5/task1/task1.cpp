#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string brand_name;
	double weight;
	int calories;
};

int main(int argc, char* argv[])
{
	int first, second;
	cout << "Enter first integer: ";
	(cin >> first).get();
	cout << "Enter second integer: ";
	(cin >> second).get();

	int sum = 0;
	for(int i = first; i<=second; i++) sum+=i;

	cout << "Sum is: " << sum << endl;

	cin.get();

	return 0;
}
