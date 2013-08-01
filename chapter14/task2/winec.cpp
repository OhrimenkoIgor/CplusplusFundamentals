
#include <iostream>

#include "winec.h"

using namespace std;

template <typename T> static void enter_number(T & n){
	while (!(cin >> n)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a number: ";
	}
	while (cin.get() != '\n'); //new line
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}

Wine::Wine(const char * l, int y) : string(l), PairArray(ArrayInt(y), ArrayInt(y)) {}

void  Wine::GetBottles(){
	cout << "Enter " << (const string &)(*this) << " data for " << first().size() << " year(s):" << endl;
	for(size_t i = 0; i < first().size(); i++){
		cout << "Enter year: ";
		enter_number(first()[i]);
		cout << "Enter bottles for that year: ";
		enter_number(second()[i]);
	}
}

void  Wine::Show() const{
	cout << "Wine: " << (const string &)(*this) << endl
		<< "Year Bottles" << endl;
	for(size_t i = 0; i < first().size(); i++){
		cout << first()[i] << " " << second()[i] << endl;
	}
}
