
#include <iostream>
#include <string>

using namespace std;


int main()
{
	cout << "Enter words (to stop, type the word done):" << endl;

	int count = 0;
	string word;
	
	while( cin >> word && word != "done") count++;

	cout << "You entered a total of " << count << " words." << endl;

	cin.get();
	cin.get();
	return 0;
}
