
#include <iostream>
#include <cstring>

#include "golf.h"

void setgolf(golf & g, const char * name, int hc){
	if (!name) return;
	strncpy(g.fullname, name, Len);
	g.handicap = hc;
}

int setgolf(golf & g){
	using namespace std;
	cout << "Enter name: ";
	cin.getline(g.fullname, Len);
	if(!g.fullname[0]){
		g.handicap = 0;
		return 0;
	}
	cout << "Enter handicap: ";
	while (!(cin >> g.handicap)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a number: ";
	}
	cin.get();
	return 1;
}

void handicap(golf & g, int hc){
	g.handicap = hc;
}

void showgolf(const golf & g){
	std::cout << g.fullname << ", " << g.handicap << std::endl;
}