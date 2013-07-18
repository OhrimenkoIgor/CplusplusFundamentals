
#include <iostream>
#include <cstring>

#include "person.h"

Person::Person(const string & ln, const char * fn){
	lname = ln;
	if (fn) {
		strncpy(fname, fn, LIMIT);
	} else{
		fname[0] = '\0';
	}
}

void Person::Show() const{
	std::cout << fname << " " << lname;
}

void Person::FormalShow() const{
	std::cout << lname << ", " << fname;
}