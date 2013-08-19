
#include <iostream>

int main()
{
	using namespace std;

	int ct = 0;
	char ch;
	while((ch = cin.get()) != '$'){
		ct++;
	}
	cin.putback(ch);

	cout << ct << endl;

	while(cin.get() != '\n');
	cin.get();
	return 0;
}

