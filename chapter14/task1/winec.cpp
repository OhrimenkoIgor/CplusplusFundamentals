
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

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : name(l), years_bottles(ArrayInt(yr, y), ArrayInt(bot, y)) {}

Wine::Wine(const char * l, int y) : name(l), years_bottles(ArrayInt(y), ArrayInt(y)) {}

void  Wine::GetBottles(){
	cout << "Enter " << name << " data for " << years_bottles.first().size() << " year(s):" << endl;
	for(size_t i = 0; i < years_bottles.first().size(); i++){
		cout << "Enter year: ";
		enter_number(years_bottles.first()[i]);
		cout << "Enter bottles for that year: ";
		enter_number(years_bottles.second()[i]);
	}
}

void  Wine::Show() const{
	cout << "Wine: " << name << endl
		<< "Year Bottles" << endl;
	for(size_t i = 0; i < years_bottles.first().size(); i++){
		cout << years_bottles.first()[i] << " " << years_bottles.second()[i] << endl;
	}
}
