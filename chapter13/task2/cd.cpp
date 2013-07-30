
#include <cstring>
#include <iostream>

#include "cd.h"

using namespace std;

Cd::Cd(char * s1, char * s2, int n, double x): selections(n), playtime(x) {
	if(s1){
		performers = new char [strlen(s1) + 1];
		strcpy(performers, s1);
	} else {
		//I think it is better to allocate 1 char and to assign 0 to it
		//and to use cstring functions safely,
		//then to check is the poiner not null before every strlen(), etc
		performers = new char [1];
		performers[0] = '\0';
	}
	if(s2){
		label = new char [strlen(s2) + 1];
		strcpy(label, s2);
	} else {
		label = new char [1];
		label[0] = '\0';
	}
}

Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime) {
	performers = new char [strlen(d.performers) + 1];
	strcpy(performers, d.performers);

	label = new char [strlen(d.label) + 1];
	strcpy(label, d.label);
}

Cd::~Cd(){
	delete [] performers;
	delete [] label;
}

void Cd::Report() const{
	cout << performers << endl
		<< label << endl
		<< selections << " selections" << endl
		<< "playtime " << playtime << endl; 
}

Cd & Cd::operator=(const Cd & d){
	if(this != &d){
		selections = d.selections;
		playtime = d.playtime;

		delete [] performers;
		performers = new char [strlen(d.performers) + 1];
		strcpy(performers, d.performers);

		delete [] label;
		label = new char [strlen(d.label) + 1];
		strcpy(label, d.label);
	}

	return *this;
}
