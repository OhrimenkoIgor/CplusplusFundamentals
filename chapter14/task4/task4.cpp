
// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include <string>
#include "classes.h"
const int SIZE = 5;

template <typename T> static void enter_number(T & n){
	while (!(std::cin >> n)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Please enter a number: ";
	}
	while (std::cin.get() != '\n'); //new line
}

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	Person * persons[SIZE];
	std::string fname, lname;
	double draw_time;
	int notches;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		cout << "Enter category:\n"
			<< "p: peson g: gunslinger "
			<< "c: poker player b: bad dude q: quit\n";
		cin >> choice;
		while (strchr("pgcbq", choice) == NULL)
		{
			cout << "Please enter a p, g, c, b or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		while(cin.get() != '\n'); //new line

		cout << "Enter first name: ";
		cin >> fname;
		cout << "Enter last name: ";
		cin >> lname;

		switch(choice)
		{
		case 'p': 
			persons[ct] = new Person(fname, lname);
			break;
		case 'g': 
		case 'b':
			cout << "Enter draw time: ";
			enter_number(draw_time);
			cout << "Enter notches: ";
			enter_number(notches);
			persons[ct] = (choice == 'g') ? new Gunslinger(fname, lname, draw_time, notches) : new BadDude(fname, lname, draw_time, notches);
			break;
		case 'c': 
			persons[ct] = new PokerPlayer(fname, lname);
			break;
		}
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		persons[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete persons[i];
	cout << "Bye.\n";

	while(cin.get() != '\n');
	cin.get();

	return 0;
}
