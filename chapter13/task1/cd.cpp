
#include <cstring>
#include <iostream>

#include "cd.h"

using namespace std;

Cd::Cd(char * s1, char * s2, int n, double x): selections(n), playtime(x) {
	if(s1){
		strncpy(performers, s1, 49);
		performers[49] = '\0';
	} else {
		performers[0] = '\0';
	}
	if(s2){
		strncpy(label, s2, 19);
		label[19] = '\0';
	} else {
		label[0] = '\0';
	}
}

void Cd::Report() const{
	cout << performers << endl
		<< label << endl
		<< selections << " selections" << endl
		<< "playtime " << playtime << endl; 
}
