#include <iostream>
using namespace std;

int main(){

	cout << "Please enter one of the following choices:" << endl
		<< "c) carnivore p) pianist" << endl
		<< "t) tree g) game" << endl;

	char choice;
	while (cin >> choice){
		switch(choice){
		case 'c' : cout << "A choice is a carnivore" << endl;
			goto end;
		case 'p' : cout << "A choice is a pianist" << endl;
			goto end;
		case 't' : cout << "A choice is a tree" << endl;
			goto end;
		case 'g' : cout << "A choice is a game" << endl;
			goto end;
		default : cout << "Please enter a c, p, t, or g: ";
		}
	}

end:
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	return 0;
}
