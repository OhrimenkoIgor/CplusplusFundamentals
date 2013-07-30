
#include <cstring>
#include <iostream>

#include "classic.h"

using namespace std;

Classic::Classic(char * s0, char * s1, char * s2, int n, double x): Cd(s1, s2, n, x) {
	if(s0){
		primary_work = new char [strlen(s0) + 1];
		strcpy(primary_work, s0);
	} else {
		primary_work = new char[1];
		primary_work[0] = '\0';
	}
}

Classic::Classic(const Classic & d): Cd(d){
	primary_work = new char [strlen(d.primary_work) + 1];
	strcpy(primary_work, d.primary_work);
}

void Classic::Report() const{
	cout << primary_work << endl;
	Cd::Report();
}

Classic::~Classic(){
	delete [] primary_work;
}

Classic & Classic::operator=(const Classic & d){
	if (this != &d){
		Cd::operator=(d);

		delete [] primary_work;
		primary_work = new char [strlen(d.primary_work) + 1];
		strcpy(primary_work, d.primary_work);
	}

	return *this;
}