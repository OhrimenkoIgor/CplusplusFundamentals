
#include <iostream>

#include "classes.h"

using std::cout;
using std::cin;
using std::endl;

void Person::Show() const{
	cout << fname << " " << lname << endl;
}

void Gunslinger::Show() const{
	Person::Show();
	cout << "Draw time: " << draw_time << endl
		<< "Notches: " << notches << endl;
}

void BadDude::Show() const{
	Gunslinger::Show();
	cout << "Card: " << Cdraw() << endl;
}
