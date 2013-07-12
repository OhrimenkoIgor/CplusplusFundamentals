
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	cout << "Enter words (to stop, type the word done):" << endl;

	int count = 0;
	char word[20] = "";
	
	while( cin >> word && strcmp(word, "done")) count++;

	cout << "You entered a total of " << count << " words." << endl;

	cin.get();
	cin.get();
	return 0;
}
