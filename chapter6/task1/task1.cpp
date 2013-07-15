#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	char ch;
	while ((ch = cin.get()) != '@'){
		if(!isdigit(ch)){
			if(isupper(ch))
				ch = tolower(ch);
			else if (islower(ch))
				ch = toupper(ch);
			cout << ch;
		}
	}


	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}