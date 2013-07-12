
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter number of rows: ";

	int rows = 0;
	(cin >> rows).get();
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < rows - i - 1; j++) cout.put('.');
		for(int j = 0; j < i+1; j++) cout.put('*');
		cout << endl;
	}
	
	cin.get();
	return 0;
}