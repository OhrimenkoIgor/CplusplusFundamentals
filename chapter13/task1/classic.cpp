
#include <cstring>
#include <iostream>

#include "classic.h"

using namespace std;

Classic::Classic(char * s0, char * s1, char * s2, int n, double x): Cd(s1, s2, n, x) {
	if(s0){
		strncpy(primary_work, s0, 49);
		primary_work[49] = '\0';
	} else {
		primary_work[0] = '\0';
	}
}

void Classic::Report() const{
	cout << primary_work << endl;
	Cd::Report();
}
