/*
Redo Listing 9.9,replacing the character array with a stringobject.The program
should no longer have to check whether the input string fits,and it can compare
the input string to ""to check for an empty line.
*/

// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// constants

// function prototype
void strcount(std::string);
int main()
{
	using namespace std;
	string input;
	cout << "Enter a line:\n";
	getline(cin, input);
	while (input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";

	cin.get();
	return 0;
}
void strcount(std::string str)
{
	using namespace std;
	static int total = 0; // static local variable
	int count = str.length(); // automatic local variable
	cout << "\"" << str <<"\" contains ";
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}