
#include <iostream>

long double probability(unsigned numbers, unsigned picks, unsigned meganumber);
int main()
{
	using namespace std;
	double total, choices, meganumber;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed and total number of of choices for meganumber:\n";
	while ((cin >> total >> choices >> meganumber) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices, meganumber); // compute the odds
		cout << " of winning.\n";
		cout << "Next three numbers (q to quit): ";
	}
	cout << "bye\n";

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks, unsigned meganumber)
{
	long double result = 1.0; // here come some local variables
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ;
	return result * (1 / double(meganumber));
}