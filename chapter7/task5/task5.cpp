
#include <iostream>

using namespace std;

int factorial(int n){
	if(n < 0) return 0;
	if (n) return n * factorial(n-1);
	else return 1;
}

int main(){
	int n;
	while (cout << "Enter number: ", cin >> n){
		cout << "Factorial is: " << factorial(n) << endl;
	}
	cin.clear();

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}