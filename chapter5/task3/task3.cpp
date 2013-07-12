
#include <iostream>
#include <array>

using namespace std;

int main()
{
	int sum = 0;
	int entry;

	cout << "Enter numbers:" << endl;
	
	while (cin >> entry && entry != 0){
		sum+=entry;
		cout << "Sum is: " << sum << endl;
	}

	cin.get();
	cin.get();
	return 0;
}
